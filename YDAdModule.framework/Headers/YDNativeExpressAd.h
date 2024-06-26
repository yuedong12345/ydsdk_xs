//
//  YDNativeExpressAd.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YDSDKDefines.h"

@class YDNativeExpressView;
@class YDNativeExpressAd;

@protocol YDNativeExpressAdDelegete<NSObject>

@optional

/// 原生广告加载成功
/// - Parameters:
///   - nativeExpressAd: YDNativeExpressAd
///   - views: YDNativeExpressView
- (void)nativeExpressAdDidSuccessLoaded:(YDNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof YDNativeExpressView *> *)views;

/// 原生广告加载失败
/// - Parameters:
///   - nativeExpressAd: YDNativeExpressAd
///   - error: 错误信息
- (void)nativeExpressAdDidFailLoaded:(YDNativeExpressAd *)nativeExpressAd error:(NSError *)error;


/// 原生广告渲染成功,  此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidRenderSuccess:(YDNativeExpressView *)nativeExpressAdView;

/// 原生广告渲染失败
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidRenderFail:(YDNativeExpressView *)nativeExpressAdView;

/// 原生广告曝光
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidExposed:(YDNativeExpressView *)nativeExpressAdView;

/// 原生广告点击
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidClicked:(YDNativeExpressView *)nativeExpressAdView;

/// 原生广告点击关闭按钮
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidClickedCloseButton:(YDNativeExpressView *)nativeExpressAdView;

/// 原生广告被关闭
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidClosed:(YDNativeExpressView *)nativeExpressAdView;

/// 点击原生广告以后即将弹出详情页面
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewWillShowDetailPage:(YDNativeExpressView *)nativeExpressAdView;

/// 点击原生广告以后弹出详情页面
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidShowDetailPage:(YDNativeExpressView *)nativeExpressAdView;

/// 广告详情页将要关闭
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewWillDismissDetailPage:(YDNativeExpressView *)nativeExpressAdView;

/// 广告详情页关闭
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidDismissDetailPage:(YDNativeExpressView *)nativeExpressAdView;

/// 原生模板视频广告 player 播放状态更新回调
/// - Parameters:
///   - nativeExpressAdView: YDNativeExpressView
///   - status: YDPlayerStatus
- (void)nativeExpressAdView:(YDNativeExpressView *)nativeExpressAdView playerStatusChanged:(YDPlayerStatus)status;

/// 原生视频广告详情页 将要展示
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewWillPresentVideoVC:(YDNativeExpressView *)nativeExpressAdView;

/// 原生视频广告详情页 展示
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidPresentVideoVC:(YDNativeExpressView *)nativeExpressAdView;

/// 原生视频广告详情页 WillDismiss
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewWillDismissVideoVC:(YDNativeExpressView *)nativeExpressAdView;

/// 原生视频广告详情页 DidDismiss
/// - Parameter nativeExpressAdView: YDNativeExpressView
- (void)nativeExpressAdViewDidDismissVideoVC:(YDNativeExpressView *)nativeExpressAdView;

/// dislikeView 点击了蒙层关闭
/// - Parameter nativeExpressAd: YDNativeExpressAd
/// - Parameter text: dislikeText
- (void)nativeExpressAdDislikeDidClickMask:(YDNativeExpressAd *)nativeExpressAd adView:(YDNativeExpressView *)adView;

/// dislikeView 选择了某一项
/// - Parameter nativeExpressAd: YDNativeExpressAd
/// - Parameter text: dislikeText
- (void)nativeExpressAd:(YDNativeExpressAd *)nativeExpressAd adView:(YDNativeExpressView *)adView dislikeDidSelectText:(NSString *)text;

@end

@interface YDNativeExpressAd : NSObject

/// delegate
@property (nonatomic, weak) id<YDNativeExpressAdDelegete> delegate;

@property (nonatomic, strong) NSDictionary *extParam;

/// 拉取广告超时时间
@property (nonatomic, assign) CGFloat fetchDelay;

// 是否拦截Dislike关闭按钮
@property (nonatomic, assign) BOOL hookDislikeButton;

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

/// 初始化
/// @param scene 场景
/// @param size 广告展示的宽高
- (instancetype)initWithScene:(NSString *)scene adSize:(CGSize)size;

/// 拉取广告
/// @param count 请求广告数量
- (void)loadAd:(NSInteger)count;

/// 预加载广告
/// @param scene 场景号
- (void)preloadWithScene:(NSString *)scene;

/// 展示dislikeView
- (void)showDislikeFrom:(UIViewController *)rootViewController;

@end
