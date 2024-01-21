#ifndef COMMAND_H
#define COMMAND_H
#include <QString>
struct motorCMD
{
    //读取电机状态 1 和错误标志命令
    QString readMotorState1CMD = QStringLiteral("3e 9A %1 00");

    //清除电机错误标志命令
    QString clearMotorErrorCMD = QStringLiteral("3e 9B %1 00");

    //读取电机状态 2 命令
    QString readMotorState2CMD = QStringLiteral("3e 9C %1 00");

    //读取电机状态 3 命令
    QString readMotorState3CMD = QStringLiteral("3e 9d %1 00");

    //电机运行命令
    QString motorOpenCMD = QStringLiteral("3e 88 %1 00");

    //电机关闭命令
    QString motorCloseCMD = QStringLiteral("3e 80 %1 00");

    //电机停止命令
    QString motorStopCMD = QStringLiteral("3e 81 %1 00");

    //速度闭环控制命令
    QString speedConcrolCMD = QStringLiteral("3e A2 %1 04");

    //多圈位置闭环控制命令 1
    QString angleConcrolCMD1 = QStringLiteral("3e A3 %1 0C");

    //多圈位置闭环控制命令 2
    QString angleConcrolCMD2 = QStringLiteral("3e A4 %1 0C");

    //写入设定参数到 ROM 命令
    QString writeParameterToROMCMD = QStringLiteral("3e 44 %1 07");

    //写入设定参数到 RAM 命令
    QString writeParameterToRAMCMD = QStringLiteral("3e 42 %1 07");

    //读取设定参数命令
    QString readParameterCMD = QStringLiteral("3e 40 %1 02");

    //读取驱动和电机型号命令
    QString readmotorTypeCMD = QStringLiteral("3e 12 %1 00");

    //读取多圈角度命令
    QString readmotorangleCMD = QStringLiteral("3e 92 %1 00");
};

struct motorDATA
{
    //数据填充都是先低后高

    //速度闭环控制命令 DATA[0]-[3]为maxspeed
    QString speedConcrolDATA = QStringLiteral("%1 %2 %3 %4");

    //多圈位置闭环控制命令 1 DATA[0]-[7]为angle
    QString angleConcrolDATA1 = QStringLiteral("%1 %2 %3 %4 %5 %6 %7 %8");

    //多圈位置闭环控制命令 2 DATA[0]-[7]为angle,DATA[8]-[12]为maxspeed
    QString angleConcrolDATA2 = QStringLiteral("%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11 %12");

    //写入设定参数到 ROM 命令 DATA[0]为prama 其余为参数值
    QString writeParameterToROMDATA = QStringLiteral("%1 %2 %3 %4 %5 %6 %7");

    //写入设定参数到 RAM 命令 DATA[0]为Param 其余为参数值
    QString writeParameterToRAMDATA = QStringLiteral("%1 %2 %3 %4 %5 %6 %7");

    //读取设定参数命令 DATA[1]为Param
    QString readParameterDATA = QStringLiteral("00 %1");

};

struct motorParam
{
    //角度环 pid
    QString anglePid = QStringLiteral("96 %1 %2 %3 %4 %5 %6");

    //速度环 pid
    QString speedPid = QStringLiteral("97 %1 %2 %3 %4 %5 %6");

    //最大速度
    QString maxSpeed = QStringLiteral("9A %1 %2 %3 %4");

    //最大角度低 4 字节
    QString maxAngleLOW = QStringLiteral("9B %1 %2 %3 %4");

    //最大角度高 4 字节
    QString maxAngleHIGH = QStringLiteral("9C %1 %2 %3 %4");

    //速度斜率
    QString speedRamp = QStringLiteral("9E %1 %2 %3 %4");
};








#endif // COMMAND_H
