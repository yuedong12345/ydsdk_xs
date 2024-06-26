//
//  YDRewardVideoAd.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YDRewardVideoAd;

@protocol YDRewardedVideoAdDelegate<NSObject>

@optional

/// 广告加载成功
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoDidLoad:(YDRewardVideoAd *)rewardedVideoAd;

/// 视频下载成功
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoVideoDidLoad:(YDRewardVideoAd *)rewardedVideoAd;

/// 视频播放页即将展示
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoWillVisible:(YDRewardVideoAd *)rewardedVideoAd;

/// 视频广告曝光
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoDidExposed:(YDRewardVideoAd *)rewardedVideoAd;


/// 视频播放页关闭
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoDidClose:(YDRewardVideoAd *)rewardedVideoAd;


/// 视频点击
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoDidClicked:(YDRewardVideoAd *)rewardedVideoAd;

/// 错误信息回调
/// @param rewardedVideoAd YDRewardVideoAd
/// @param error 错误信息
- (void)rewardVideoAd:(YDRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;


/// 视频播放达到激励条件
/// @param rewardedVideoAd YDRewardVideoAd
/// @param info 信息 adType(广告类型):  csj/gdt/ks/baidu   verify: 1/0  其它源回调的 字段 如 GDT: GDT_TRANS_ID 交易id
- (void)rewardVideoDidRewardEffective:(YDRewardVideoAd *)rewardedVideoAd info:(NSDictionary *)info;


/// 视频播放完成
/// @param rewardedVideoAd YDRewardVideoAd
- (void)rewardVideoDidPlayFinish:(YDRewardVideoAd *)rewardedVideoAd;

@end

@interface YDRewardVideoAd : NSObject

/// delegate
@property (nonatomic, weak) id<YDRewardedVideoAdDelegate> delegate;

/// 静音
@property (nonatomic, assign) BOOL videoMuted;

/// 过期时间
@property (nonatomic, assign, readonly) NSInteger expiredTimestamp;

/// 广告是否有效 广告加载成功  未曝光  未过期时，为YES，否则为NO
@property (nonatomic, assign, readonly) BOOL isAdValid;

/// extra 扩展信息 最后会通过 rewardVideoDidRewardEffective info 字段透传回去
@property (nonatomic, copy, nullable) NSString *extra;

/// 构造方法
/// - Parameter scene: 场景id
- (instancetype)initWithScene:(NSString *)scene;

- (void)preload;

/// 只拉取不展示
- (void)loadAd;

/// 激励视频时长 如果不是激励视频 0
- (CGFloat)videoDuration;

/// 展示广告
/// @param rootViewController 用于 present 激励视频 VC
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
