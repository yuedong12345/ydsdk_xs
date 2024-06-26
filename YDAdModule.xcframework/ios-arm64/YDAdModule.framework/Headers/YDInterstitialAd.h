//
//  YDInterstitialAd.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/21.
//

#import <Foundation/Foundation.h>
#import "YDSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN


@class YDInterstitialAd;

@protocol YDInterstitialAdDelegate<NSObject>
@optional

/// 广告源返回插屏广告数据成功
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialSuccessToLoaded:(YDInterstitialAd *)interstitial;

/// 广告源返回广告数据失败
/// - Parameters:
///   - interstitial: YDInterstitialAd
///   - error: 错误信息
- (void)interstitialFailToLoaded:(YDInterstitialAd *)interstitial error:(NSError *)error;

/// 广告视频缓存完成
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidDownloadVideo:(YDInterstitialAd *)interstitial;


/// 广告渲染成功 建议此回调后展示广告
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidRenderSuccess:(YDInterstitialAd *)interstitial;

/// 广告渲染失败
/// - Parameters:
///   - interstitial: YDInterstitialAd
///   - error: 失败信息
- (void)interstitialDidRenderFail:(YDInterstitialAd *)interstitial error:(NSError *)error;

/// 广告将要展示
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialWillPresentedOnScreen:(YDInterstitialAd *)interstitial;

/// 广告视图展示成功回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidPresentOnScreen:(YDInterstitialAd *)interstitial;

/// 广告视图展示失败回调
/// - Parameters:
///   - interstitial: YDInterstitialAd
///   - error: 错误信息
- (void)interstitialFailToPresent:(YDInterstitialAd *)interstitial error:(NSError *)error;

/// 广告展示结束回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidDismissScreen:(YDInterstitialAd *)interstitial;

/// 广告曝光回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialWillExposed:(YDInterstitialAd *)interstitial;

/// 广告点击回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidClicked:(YDInterstitialAd *)interstitial;

/// 广告点击后即将展示详情回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialWillShowDetailPage:(YDInterstitialAd *)interstitial;

/// 广告点击后展示详情回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidShowDetailPage:(YDInterstitialAd *)interstitial;

/// 详情页将要关闭回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialWillDismissDetailPage:(YDInterstitialAd *)interstitial;

/// 详情页关闭回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialDidDismissDetailPage:(YDInterstitialAd *)interstitial;


/// 视频广告 player 播放状态更新回调
/// - Parameters:
///   - interstitial: YDInterstitialAd
///   - status: 播放器状态
- (void)interstitialAd:(YDInterstitialAd *)interstitial playerStatusChanged:(YDPlayerStatus)status;

/// 插屏视频广告详情页 WillPresent 回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialViewWillPresentVideoVC:(YDInterstitialAd *)interstitial;

/// 插屏视频广告详情页 DidPresent 回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialViewDidPresentVideoVC:(YDInterstitialAd *)interstitial;

/// 插屏视频广告详情页 WillDismiss 回调
/// - Parameter interstitial: YDInterstitialAd
- (void)interstitialViewWillDismissVideoVC:(YDInterstitialAd *)interstitial;

/// 插屏视频广告详情页 DidDismiss 回调
/// @param interstitial YDInterstitialAd
- (void)interstitialAdViewDidDismissVideoVC:(YDInterstitialAd *)interstitial;

/// 插屏激励广告视频播放达到激励条件回调（注意: 只有插屏激励广告位才会有此回调）
/// @param interstitial YDInterstitialAd
/// @param info 其它广告信息
- (void)interstitialAdDidRewardEffective:(YDInterstitialAd *)interstitial info:(NSDictionary *)info;

@end

@interface YDInterstitialAd : NSObject

/// delegate
@property (nonatomic, weak) id<YDInterstitialAdDelegate> delegate;

@property (nonatomic, assign) CGFloat fetchDelay;

/// 广告是否有效 广告加载成功  未曝光  未过期时，为YES，否则为NO
@property (nonatomic, assign, readonly) BOOL isAdValid;

/// 非 WiFi 网络，是否自动播放 默认 YES
@property (nonatomic, assign) BOOL videoAutoPlayOnWWAN;

/// 自动播放时，是否静音。默认 YES
@property (nonatomic, assign) BOOL videoMuted;

/// 视频详情页播放时是否静音。默认NO
@property (nonatomic, assign) BOOL detailPageVideoMuted;

/// 请求视频的时长下限
@property (nonatomic, assign) NSInteger minVideoDuration;

/// 请求视频的时长上限
@property (nonatomic, assign) NSInteger maxVideoDuration;

/// 是否是视频广告
@property (nonatomic, assign, readonly) BOOL isVideoAd;

/// 初始化方法
/// @param scene 场景
- (instancetype)initWithScene:(NSString *)scene;

/// 请求广告
- (void)loadAd;

/// 展示插屏广告
/// - Parameter rootViewController: rootVC
- (void)presentAdFromRootViewController:(UIViewController *)rootViewController;

/// 视频插屏广告时长，单位 ms
- (CGFloat)videoDuration;

/// 视频插屏广告已播放时长，单位 ms
- (CGFloat)videoPlayTime;

@end

NS_ASSUME_NONNULL_END
