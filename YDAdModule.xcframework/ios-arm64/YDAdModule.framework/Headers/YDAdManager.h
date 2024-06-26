//
//  YDAdManager.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YDAdManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

/// 初始化
+ (void)setup;

/// 设置全局广告开关 默认开
/// - Parameter enabled: true 开 false 关
+ (void)setGlobalAdSwitch:(BOOL)enabled;

/// 是否是VIP  用户只展示开屏
/// - Parameter isVip:
+ (void)setVipSwitch:(BOOL)isVip;

+ (void)enableDefaultAudioSessionSetting:(BOOL)enabled;

/// 个性化推荐状态开关
/// - Parameter state: 状态  1  关闭 其它开启
+ (void)setPersonalizedState:(NSInteger)state;

+ (NSString *)sdkVersion;

+ (BOOL)isCSJInitComplete;
@end

NS_ASSUME_NONNULL_END
