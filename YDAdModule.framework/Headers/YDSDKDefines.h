//
//  YDSDKDefines.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/23.
//

#ifndef YDSDKDefines_h
#define YDSDKDefines_h

typedef NS_ENUM(NSUInteger, YDPlayerStatus) {
    YDPlayerStatusInitial = 0,         // 初始状态
    YDPlayerStatusLoading = 1,         // 加载中
    YDPlayerStatusStarted = 2,         // 开始播放
    YDPlayerStatusPaused = 3,          // 用户手动暂停
    YDPlayerStatusError = 4,           // 播放失败
    YDPlayerStatusStoped = 5,          // 播放结束
    YDPlayerStatusWillStart = 10,      // 即将播放
};

#endif /* YDSDKDefines_h */
