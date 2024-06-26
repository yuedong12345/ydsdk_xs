//
//  YDSplashAd.h
//  YDAdModule
//
//  Created by YueDong on 2023/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YDSplashAd;

@protocol YDSplashAdDelegate<NSObject>

@optional

/**
 * 开屏素材加载成功
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDidLoad:(YDSplashAd *)splashAd;

/**
 * 开屏成功展示
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashSuccessPresented:(YDSplashAd *)splashAd;

/**
 * 开屏展示失败
 * - Parameters:
 *   - splashAd: YDSplashAd
 *   - error: error
 */
- (void)splashFailToPresented:(YDSplashAd *)splashAd withError:(NSError *)error;

/**
 * 开屏曝光
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDidExposed:(YDSplashAd *)splashAd;

/**
 * 开屏剩余时间
 * - Parameter time: 剩余时间
 */
- (void)splashLeftTime:(NSUInteger)time;

/**
 * 开屏点击
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDidClicked:(YDSplashAd *)splashAd;

/**
 * 开屏广告将要关闭
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashWillClosed:(YDSplashAd *)splashAd;

/**
 * 开屏广告关闭
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDidClosed:(YDSplashAd *)splashAd;

/**
 * 开屏被点击以后即将展示详情页面
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashWillShowDetailPage:(YDSplashAd *)splashAd;

/**
 * 开屏点击以后详情页面弹出
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDidShowDetailPage:(YDSplashAd *)splashAd;

/**
 * 点击以后详情页面将要关闭
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDetailPageWillDismiss:(YDSplashAd *)splashAd;

/**
 * 点击以后详情页面关闭了
 * - Parameter splashAd: YDSplashAd
 */
- (void)splashDetailPageDidDismiss:(YDSplashAd *)splashAd;

@end

@interface YDSplashAd : NSObject

/// delegate
@property (nonatomic, weak) id<YDSplashAdDelegate> delegate;

/// 拉取广告超时时间
@property (nonatomic, assign) CGFloat fetchDelay;

/// bottomView 可以展示logo的 放在window的底部
@property (nonatomic, strong) UIView *bottomView;

/// 广告是否有效 广告加载成功  未曝光  未过期时，为YES，否则为NO
@property (nonatomic, assign, readonly) BOOL isAdValid;

///// 是否正在显示开屏
//@property (nonatomic, assign, readonly) BOOL isShowing;

/// 构造方法
/// - Parameter scene: 场景id
- (instancetype)initWithScene:(NSString *)scene;

/// 预加载开屏
/// @param scene 场景号
- (void)preloadWithScene:(NSString *)scene;

/// 只拉取不展示  成功后 走 splashDidLoad 失败 走 splashFailToPresented
- (void)loadAd;

/// 展示广告，先判断 isAdValid 方法返回的广告是否有效
/// - Parameter window: window
/// - Parameter bottomView: bottomView
- (void)showAdInWindow:(UIWindow *)window bottomView:(UIView *_Nullable)bottomView skipView:(UIView *_Nullable)skipView;

/// 加载并等待展示
/// - Parameters:
///   - window: window
///   - bottomView: bottomView
- (void)loadAdAndShowInWindow:(UIWindow *)window bottomView:(UIView *_Nullable)bottomView skipView:(UIView *_Nullable)skipView;

@end

NS_ASSUME_NONNULL_END
