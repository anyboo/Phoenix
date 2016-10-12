#ifndef DZM_ACTIONCTROL_H
#define DZM_ACTIONCTROL_H

#include "GlobalTypes.h"

//0x00-0x63通用功能
//0x00-0x2f解码器控制
#define     REGISTER                0         //注册功能
#define     MOVE_UP                 1         //云台向上
#define     MOVE_UP_STOP            2         //云台向上停
#define     MOVE_DOWN               3         //云台向下
#define     MOVE_DOWN_STOP          4         //云台向下停
#define     MOVE_LEFT               5         //云台向左
#define     MOVE_LEFT_STOP          6         //云台向左停
#define     MOVE_RIGHT              7         //云台向右
#define     MOVE_RIGHT_STOP         8         //云台向右停
#define     MOVE_UP_LEFT            9         //云台左上
#define     MOVE_UP_LEFT_STOP       10        //云台左上停
#define     MOVE_UP_RIGHT           11        //云台右上
#define     MOVE_UP_RIGHT_STOP      12        //云台右上停
#define     MOVE_DOWN_LEFT          13        //云台左下
#define     MOVE_DOWN_LEFT_STOP     14        //云台左下停
#define     MOVE_DOWN_RIGHT         15        //云台右下
#define     MOVE_DOWN_RIGHT_STOP    16        //云台右下停
#define     SET_LEFT_BORDER         17        //设置左边界
#define     SET_RIGHT_BORDER        18        //设置右边界
#define     SET_UP_BORDER           19        //设置上边界
#define     SET_DOWN_BORDER         20        //设置下边界
#define     HOR_AUTO                21        //水平自动
#define     HOR_AUTO_STOP           22        //水平自动停
#define     SET_HOR_AUTO_BEGIN      23        //设水平自动开始点
#define     SET_HOR_AUTO_END        24        //设水平自动结束点
#define     SET_HOR_AUTO_SPEED      25        //设置水平自动速度
#define     VER_AUTO                26        //垂直自动
#define     SET_VER_AUTO_BEGIN      27        //设置垂直自动开始点
#define     SET_VER_AUTO_END        28        //设置垂直自动结束点
#define     SET_VER_AUTO_SPEED      29        //设置垂直自动速度
#define     VER_AUTO_STOP           30        //垂直自动停

#define     ZOOM_BIG                31        //变倍大
#define     ZOOM_BIG_STOP           32        //变倍大停
#define     ZOOM_SMALL              33        //变倍小
#define     ZOOM_SMALL_STOP         34        //变倍小停
#define     FOCUS_FAR               35        //聚焦远
#define     FOCUS_FAR_STOP          36        //聚焦远停
#define     FOCUS_NEAR              37        //聚焦近
#define     FOCUS_NEAR_STOP         38        //聚焦近停
#define     IRIS_OPEN               39        //光圈开
#define     IRIS_OPEN_STOP          40        //光圈开停
#define     IRIS_CLOSE              41        //光圈关
#define     IRIS_CLOSE_STOP         42        //光圈关停

#define     LIGHT_ON                43        //灯光开
#define     LIGHT_OFF               44        //灯光关
#define     POWER_ON                45        //电源开
#define     POWER_OFF               46        //电源关
#define     RAIN_ON                 47        //雨刷开
#define     RAIN_OFF                48        //雨刷关
#define     TALK_ON                 49        //对讲开
#define     TALK_OFF                50        //对讲关
#define     DEF_ON                  51        //布防
#define     DEF_OFF                 52        //撤防

#define     BROWSE                  53        //查询
#define     ALARM_ANSWER            54        //报警应答
#define     STATE_ASK               55        //请求上传控制状态

//0x30-0x4f快球控制
#define     MOVE                    60        //快球动作
#define     MOVE_STOP               61        //快球动作停
#define     CALL_VIEW               62        //调用预置景点
#define     SET_VIEW                63        //设置预置景点
#define     GET_VIEW_LIST           64        //获得预置景点序列
#define     DELETE_VIEW             65        //删除预置景点
#define     SEQUENCE_BEGIN          66        //开始巡航
#define     SEQUENCE_END            67        //停止巡航
#define     ADD_PRESET              68        //添加巡航点
#define     DELETE_PRESET           69        //删除巡航点
#define     GET_TRACK_SEQUENCE      70        //获得巡航序列
#define     CLEAR_SEQUENCE          71        //清除巡航设置
#define     SET_GUARD               72        //设置看守位
#define     DELETE_GUARD            73        //删除看守位
#define     GET_GUARD_DELAY         74        //获得看守位的延迟时间
#define     GET_HOR_AUTO_SPEED      75        //获得水平自动速度
#define     GET_VER_AUTO_SPEED      76        //获得垂直自动速度

//模式路径
#define			Pattern_Start			81				//模式路径开始点（花样扫描开始点）
#define			Pattern_Stop			82				//模式路径结束点（花样扫描结束点）
#define			Run_Pattern 			83				//开始模式路径（开始花样扫描）
#define			Stop_Pattern 			84				//停止模式路径（停止花样扫描）
//巡航
#define			SEQUENCE_Time			85				//巡航组停留时间
#define         Set_Guard_Time          86             //设置巡航时间

//0x64-0xc7专用功能
#define     SWITCH                  101        //手动矩阵切换
#define     SWITCH_MONITOR          102        //切监
#define     SWITCH_VIDICON          103        //切点
#define     SWITCH_ORDER            104        //顺序切换
#define     SWITCH_ORDER_STOP       105        //顺序切换停
#define     SWITCH_GROUP            106        //群组切换
#define     SWITCH_GROUP_STOP       107        //群组切换停
//守望功能
#define 		Guard_Link_Present			129				//设置守望功能预制位
#define 		Guard_Link_AutoScan			130				//设置守望功能自动扫描
#define 		Guard_Link_Cruise			131				//设置守望功能自动巡航
#define 		Guard_Link_Pattern			132				//设置守望功能模式路径

#define     ABSOLUTEMARK     135        //3d绝对坐标
#define     OPPOSITEMARK     136        //3d相对坐标

#define DOME_PLUS   150
#define DOME_PELCO_D  151
#define DOME_PELCO_P  152

struct Data_t
{
	int iAddress;   //設備地址
	int iPreset;	//預置景點
	POINT point;//移動時的座標點
	unsigned char  DecBuf[256];//輸出資料的個數
	int   iCount;//in and out,輸入輸出的個數
	int   iGuardTime;//守望时间
	int  param[7];//3D定位坐标填充此数组，以上参数忽略
};

#endif
