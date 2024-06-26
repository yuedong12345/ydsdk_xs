//
//  YDBannerView.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YDBannerView;

@protocol YDBannerViewDelegate<NSObject>
@optional

/// 广告源返回的广告数据成功后调用
/// - Parameter bannerView: YDBannerView
- (void)bannerViewDidLoad:(YDBannerView *)bannerView;


/// 广告源返回的广告数据失败后调用
/// - Parameters:
///   - bannerView: YDBannerView
///   - error: 失败原因
- (void)bannerViewFailedToLoad:(YDBannerView *)bannerView error:(NSError *)error;


/// 曝光回调
/// - Parameter bannerView: YDBannerView
- (void)bannerViewWillExpose:(YDBannerView *)bannerView;


/// 点击回调
/// - Parameter bannerView: YDBannerView
- (void)bannerViewDidClicked:(YDBannerView *)bannerView;


/// 广告点击以后即将弹出广告详情
/// - Parameter bannerView: YDBannerView
- (void)bannerViewWillPresentDetailPage:(YDBannerView *)bannerView;


/// 广告点击以后弹出详情页
/// - Parameter bannerView: YDBannerView
- (void)bannerViewDidPresentDetailPage:(YDBannerView *)bannerView;


/// 详情即将关闭
/// - Parameter bannerView: YDBannerView
- (void)bannerViewWillDismissDetailPage:(YDBannerView *)bannerView;


/// 详情已经被关闭
/// - Parameter bannerView: YDBannerView
- (void)bannerViewDidDismissDetailPage:(YDBannerView *)bannerView;

/**
 *  当点击应用下载或者广告调用系统程序打开
 */
- (void)bannerViewWillLeaveApplication:(YDBannerView *)bannerView;


/// 被用户关闭时调用  若开启循环  刷新间隔 - 已展示事件  后会展示新的广告  如果没有开启循环 会自动移除
/// - Parameter bannerView: YDBannerView
- (void)bannerViewWillClose:(YDBannerView *)bannerView;

/// 用户点击关闭按钮
/// - Parameter bannerView: YDBannerView
- (void)bannerViewDidClickedCloseButton:(YDBannerView *)bannerView;

/// dislike 选择了某一项
/// - Parameters:
///   - bannerView: YDBannerView
///   - text: text
- (void)bannerView:(YDBannerView *)bannerView dislikeDidSelectText:(NSString *)text;
@end

@interface YDBannerView : UIView

@property (nonatomic, weak) id<YDBannerViewDelegate> delegate;

@property (nonatomic, assign) CGFloat fetchDelay;

/// 展现和轮播时的动画效果开关，默认打开
@property (nonatomic, assign) BOOL animated;

// 是否拦截Dislike关闭按钮
@property (nonatomic, assign) BOOL hookDislikeButton;

/// 广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
@property (nonatomic, assign) int autoSwitchInterval;

/// 广告是否有效 广告加载成功  未曝光  未过期时，为YES，否则为NO
@property (nonatomic, assign, readonly) BOOL isAdValid;


/// 初始化方法
/// - Parameters:
///   - scene: 场景
///   - viewController: 当前控制器
- (instancetype)initWithScene:(NSString *)scene viewController:(UIViewController *)viewController;

/// 初始化方法
/// - Parameters:
///   - frame: frame
///   - scene: 场景
///   - viewController: 当前控制器
- (instancetype)initWithFrame:(CGRect)frame scene:(NSString *)scene viewController:(UIViewController *)viewController;

- (void)loadAd;

/// 加载并展示
- (void)loadAndShow;

- (void)destoryBannerAd;

/// 展示dislikeView
- (void)showDislikeFrom:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
