/**
 * PAP Server Engine ( https://github.com/viticm/web-pap )
 * $Id Log.h
 * @link https://github.com/viticm/web-pap/tree/master/server for the canonical source repository
 * @copyright Copyright (c) 2013-2013 viticm( viticm@126.com )
 * @license
 * @user viticm<viticm@126.com>
 * @date 2013-8-13 22:25:19
 * @uses the logs module
 */

#ifndef __LOG_H__
#define __LOG_H__

#include "Type.h"
#include "File.h"
#include "LogDefine.h"


enum LOG_FILE_NAME_ID
{
    LOG_FILE_0 = 0 ,
    LOG_FILE_1 = 1 ,
    LOG_FILE_2 = 2 ,
    LOG_FILE_3 = 3 ,
    LOG_FILE_4 = 4 ,
    LOG_FILE_5 = 5 ,
    LOG_FILE_6 = 6 ,
    LOG_FILE_7 = 7 ,
    LOG_FILE_8 = 8 ,
    LOG_FILE_9 = 9 ,
    LOG_FILE_10 = 10 ,
    LOG_FILE_11 = 11 ,
    LOG_FILE_12 = 12 ,
    LOG_FILE_13 = 13 ,
    LOG_FILE_14 = 14 ,
    LOG_FILE_15 = 15 ,
    LOG_FILE_16 = 16 ,
    LOG_FILE_17 = 17 ,
    LOG_FILE_18 = 18 ,
    LOG_FILE_19 = 19 ,
    LOG_FILE_20 = 20 ,
    LOG_FILE_21 = 21 ,
    LOG_FILE_22 = 22 ,
    LOG_FILE_23 = 23 ,

    LOG_FILE_NUMBER ,
};
#define LOG_SAVE_PATH                    "./Log/"
#define LOGIN_LOGFILE                    "Login"
#define BILLING_LOGFILE                  "Billing"
#define SERVER_LOGFILE                   "Debug"
#define SERVER_ERRORFILE                 "Error"
#define WORLD_LOGFILE                    "World"
#define CONFIG_LOGFILE                   "Config"
#define ASSERT_LOGFILE                   "assert"
#define RECYCLEPLAYER_LOGFILE            "RecyclePlayer"

#define SERVER_FUNCTIONFILE              "./Log/Functions.log"

#define DEFAULT_LOG_CACHE_SIZE 1024*1024*4

class Log
{
public :
    Log() ;
    ~Log() ;

    BOOL            Init() ;

    //向日志缓存写入日志信息
    VOID            FastSaveLog( INT logid, CHAR* msg, ... ) ;

    //将日志内存数据写入文件
    VOID            FlushLog( INT logid ) ;

    // 从日志基本文件名取得对应的日志id
    INT             GetLogId( CHAR* szBaseFileName );

    //取得日志有效数据大小
    INT             GetLogSize( INT logid ){ return m_LogPos[logid] ; }

    //取得保存日志的文件名称
    VOID            GetLogName( INT logid, CHAR* szName ) ;

    //刷新每个日志文件
    VOID            FlushLog_All() ;

    //取得日期天数
    UINT            GetDayTime(){ return m_DayTime ; }

    //设置日期天数
    VOID            SetDayTime( UINT daytime ){ m_DayTime = daytime ; }


    //支持异步写入操作的日志写入
    static VOID        SaveLog( CHAR* szFileName, CHAR* szMsg, ... ) ;
    
    // 根据日志文件基本名称获得日志名称
    static INT         GetStaticLogId( CHAR* szBaseFileName );

    // 获得日志名称，不需实例化
    static VOID        GetStaticLogName( INT iLogId, CHAR* szName );

    //删除日志内容
    static VOID        RemoveLog( CHAR* filename ) ;


private :
    CHAR*                m_LogCache[LOG_FILE_NUMBER] ;    //日志内存区
    INT                  m_LogPos[LOG_FILE_NUMBER] ;      //日志当前有效数据位置
    MyLock               m_LogLock[LOG_FILE_NUMBER] ;     //日志读写锁
    INT                  m_CacheSize ;
    UINT                 m_DayTime ;
};

#if defined __LINUX__
    #define SaveCodeLog()    (Log::SaveLog( SERVER_ERRORFILE, "%s %d %s", __FILE__,__LINE__,__PRETTY_FUNCTION__ ))
#else
    #define SaveCodeLog()    (Log::SaveLog( SERVER_ERRORFILE, "%s %d %s", __FILE__,__LINE__,__FUNCTION__ ))
#endif

extern Log* g_pLog ;

#endif
