
__header = '''/**
 * AS - the open source Automotive Software on https://github.com/parai
 *
 * Copyright (C) 2015  AS <parai@foxmail.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */
'''

from .util import *

__all__ = ['gen_smallos']
def SmallOS_TaskList(os_list):
    ret_list = []
    task_list = ScanFrom(os_list,'Task')
    for task in task_list:
        length = len(ret_list)
        if(length == 0):
            ret_list.append(task)
        else:
            prio = int(task.attrib['priority'])
            flag = False
            for it in ret_list:
                iprio = int(it.attrib['priority'])
                if(prio < iprio):
                    ret_list.insert(0, task)
                    flag = True
                    break
            if(flag == False):
                ret_list.append(task)
    return ret_list
    
def genForSmallOS_H(gendir,os_list):
    fp = open('%s/Os_Cfg.h'%(gendir),'w')
    fp.write(__header)
    fp.write('#ifndef OS_CFG_H\n#define OS_CFG_H\n\n')
    fp.write('/* ============================ [ INCLUDES  ] ====================================================== */\n')
    fp.write('#include "Std_Types.h"\n')
    fp.write('#include "os_i.h"\n')
    fp.write('/* ============================ [ MACROS    ] ====================================================== */\n')
    fp.write('#define __SMALL_OS__\n\n')
    fp.write("#define OS_TICKS2MS(a) (a)\n\n")
    task_list = SmallOS_TaskList(os_list)
    for id,task in enumerate(task_list):
        fp.write('#define TASK_ID_%-32s %-3s /* priority = %s */\n'%(task.attrib['name'],id,task.attrib['priority']))
    fp.write('#define TASK_NUM%-32s %s\n\n'%(' ',id+1))
    for id,task in enumerate(task_list):
        for mask,ev in enumerate(task):
            if(ev.attrib['mask']=='auto'):
                mask = '(1<<%s)'%(mask)
            else:
                mask = ev.attrib['mask']
            fp.write('#define EVENT_MASK_%-40s %s\n'%('%s_%s'%(task.attrib['name'],ev.attrib['name']),mask))
    fp.write('\n')
    
    res_list = ScanFrom(os_list, 'Resource')
    for id,res in enumerate(res_list):
        fp.write('#define RES_ID_%-32s %s\n'%(res.attrib['name'],id+1))
    fp.write('#define RES_NUMBER %s\n\n'%(len(res_list)+1))
    
    alarm_list = ScanFrom(os_list,'Alarm')
    for id,alarm in enumerate(alarm_list):
        fp.write('#define ALARM_ID_%-32s %s\n'%(alarm.attrib['name'],id))
    fp.write('#define ALARM_NUM%-32s %s\n\n'%(' ',id+1))
    fp.write('\n\n')
    fp.write('/* ============================ [ TYPES     ] ====================================================== */\n')
    fp.write('/* ============================ [ DECLARES  ] ====================================================== */\n')
    fp.write('/* ============================ [ DATAS     ] ====================================================== */\n')
    if(len(task_list) > 0):
        fp.write('extern CONST(task_declare_t,AUTOMATIC)  TaskList[TASK_NUM];\n')
    if(len(alarm_list) > 0):
        fp.write('extern CONST(alarm_declare_t,AUTOMATIC) AlarmList[ALARM_NUM];\n')
    fp.write('/* ============================ [ LOCALS    ] ====================================================== */\n')
    fp.write('/* ============================ [ FUNCTIONS ] ====================================================== */\n')
    for id,task in enumerate(task_list):
        fp.write('extern TASK(%s);\n'%(task.attrib['name']))
    fp.write('\n\n')
    for id,alarm in enumerate(alarm_list):
        fp.write('extern ALARM(%s);\n'%(alarm.attrib['name']))
    fp.write('\n\n')
    fp.write('#endif /* OS_CFG_H */\n\n')
    fp.close()
def genForSmallOS_C(gendir,os_list):
    fp = open('%s/Os_Cfg.c'%(gendir),'w')
    fp.write(__header)
    fp.write('/* ============================ [ INCLUDES  ] ====================================================== */\n')
    fp.write('#include "Os.h"\n')
    fp.write('/* ============================ [ MACROS    ] ====================================================== */\n')
    fp.write('/* ============================ [ TYPES     ] ====================================================== */\n')
    fp.write('/* ============================ [ DECLARES  ] ====================================================== */\n')
    fp.write('/* ============================ [ DATAS     ] ====================================================== */\n')
    fp.write('/* ============================ [ LOCALS    ] ====================================================== */\n')
    fp.write('/* ============================ [ FUNCTIONS ] ====================================================== */\n')
    task_list = SmallOS_TaskList(os_list)
    fp.write('CONST(task_declare_t,AUTOMATIC)  TaskList[TASK_NUM] = \n{\n')
    for id,task in enumerate(task_list):
        fp.write('\tDeclareTask(%-32s, %-5s, %s    ),\n'%(task.attrib['name'],task.attrib['auto-start'].upper(),task.attrib['app-mode']))
    fp.write('};\n\n')
    
    alarm_list = ScanFrom(os_list,'Alarm')
    fp.write('CONST(alarm_declare_t,AUTOMATIC) AlarmList[ALARM_NUM] = \n{\n')
    for id,alarm in enumerate(alarm_list):
        fp.write('\tDeclareAlarm(%s),\n'%(alarm.attrib['name']))
    fp.write('};\n\n')
    fp.write('\n\n')
    fp.close()
def gen_smallos(gendir,os_list):
    genForSmallOS_H(gendir,os_list)
    genForSmallOS_C(gendir,os_list)