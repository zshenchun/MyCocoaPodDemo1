//
//  ETGamePlatform.h
//  ETGamePlatform
//
//  Created by ETGameSDK on 17/7/7.
//  Copyright © 2017年 ETGameSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//! Project version number for ETGamePlatform.
FOUNDATION_EXPORT double ETGamePlatformVersionNumber;

//! Project version string for ETGamePlatform.
FOUNDATION_EXPORT const unsigned char ETGamePlatformVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ETGamePlatform/PublicHeader.h>

/**
 *  IOS系统的类型
 */
typedef NS_ENUM(NSUInteger, SystemType) {
    /**
     *  越狱设备
     */
    SystemType_JailBreak = 2,
    /**
     *  非越狱设备
     */
    SystemType_AppStore = 3
};

/**
 *  支付结果，最终结果需要和游服确认
 */
typedef NS_ENUM(NSUInteger, PayResultCode) {
    /**
     *  成功
     */
    PayResultCode_Success,
    /**
     *  取消
     */
    PayResultCode_Cancel,
    /**
     *  失败
     */
    PayResultCode_Fail,
    /**
     *  正在支付z_F-B
     */
    PayResultCode_Paying
};

#pragma mark - ETGamePlatformDelegate
@protocol ETGamePlatformDelegate <NSObject>

@required

/**
 *  登录成功
 *
 *  @param token  登录令牌，需要游服到ET游戏服务端验证
 */
- (void)userLoginSuccessWithToken:(NSString *)token;

/**
 *  支付结果
 *
 *  @param code    支付结果code，参见枚举
 *  @param message 提示信息
 */
- (void)payResultWithCode:(PayResultCode)code message:(NSString *)message;


@optional

/**
 *  初始化成功回调
 */
- (void)startSuccess;

/**
 *  开始登录
 */
- (void)userLoginStart;

/**
 *  登录失败
 *
 *  @param message 失败原因描述
 */
- (void)userLoginFailWithMessage:(NSString *)message;

/**
 *  登出成功
 */
- (void)userLogoutSuccess;

/**
 *  登录取消
 */
- (void)userLoginCancel;

@end

#pragma mark - JZPlatform
@interface ETGamePlatform : NSObject

/**
 *  ET游戏平台的回调代理
 */
@property (assign, nonatomic) id<ETGamePlatformDelegate>delegate;

/**
 *  用于APP间跳转，不传则默认bundleID
 */
@property (strong, nonatomic) NSString *urlScheme;

/**
 *  渠道ID
 */
@property (strong, nonatomic) NSString *channelID;

/**
 *  ET游戏平台的单例
 *
 *  @return 单例对象
 */
+ (instancetype)getInstance;

/**
 *  初始化SDK
 *
 *
 *  @param appID        后台获取的appID
 *  @param isProtrait   是否竖屏
 *  @param systemTpye   设备类型，参照SystemType
 *  @param isDebugModal 是否开启debug模式
 *  @param delegate     回调的代理
 */
- (void)startWithAppID:(NSString *)appID  isPortrait:(BOOL)isProtrait systemType:(SystemType)systemTpye isDebugModal:(BOOL)isDebugModal delegate:(id<ETGamePlatformDelegate>)deleagate;

/**
 *  登录，显示ET游戏登录页面
 */
- (void)login;

#pragma mark - 这里新加支付
- (void)yxPay;
#pragma mark - 这里新加支付end

/**
 *  登出，置空token
 */
- (void)logout;

/**
 *  获取当前用户的ID
 *
 *  @return 获取当前用户的ID，如未登录则返回空
 */
- (NSString *)getUserID;

/**
 *  显示悬浮窗
 */
- (void)showToolBar;

/**
 *  隐藏悬浮窗
 */
- (void)hideToolBar;

/**
 * 显示防沉迷
 */
- (void)showIndulge;

- (void)showServiceCenterWithGame:(NSInteger)gameId serverId:(NSInteger)serverId  roleId:(NSInteger)roleId;
/**
 *  支付
 *
 *  @param amount  金额，必须大于等于1分，单位是分,必填
 *  @param title   标题，必填
 *  @param cpOrder 渠道订单号，必填
 *  @param ext1    扩展字段1，可为空
 *  @param ext2    扩展字段2，可为空
 *  @param ext3    扩展字段3，可为空
 */
- (void)payWithAmount:(float)amount title:(NSString *)title cpOrder:(NSString *)cpOrder ext1:(id)ext1 ext2:(id)ext2 ext3:(id)ext3;

/**
 *  支付
 *
 *  @param amount  金额，必须大于等于1分，单位是分,必填
 *  @param cpOrderId  订单号
 *  @param productName 商品名称
 *  @Param extend 扩展字段
 *  @param gameArea    角色所在服务区名称
 *  @param gameAreaId   角色所在服务区ID
 *  @param roleId   角色ID
 *  @Param userRole  角色名或者玩家昵称
 *  @param gameLevel  角色等级
 *  @param sign  sign签名，由游戏服务器生成。生成规则请参考游戏服务器接口文档
 */

//- (void)payWithAmount:(int)amount andCpOrderId:(NSString *)cpOrderId andProductName:(NSString *)productName andExtend:(id)extend andGameArea:(NSString*)gameArea andGameAreaId:(NSString*)gameAreaId andGameRoleId:(NSString*)roleId andUserRole:(NSString*)userRole andGameLevel:(NSString*)gameLevel andAppleProductId:(NSString*)appleProductId andsign:(NSString*)sign;

/**
 *  支付
 *
 *  @param amount  金额，必须大于等于1分，单位是分,必填
 *  @param cpOrderId  订单号
 *  @param productName 商品名称
 *  @Param extend 扩展字段
 *  @param gameArea    角色所在服务区名称
 *  @param gameAreaId   角色所在服务区ID
 *  @param roleId   角色ID
 *  @Param userRole  角色名或者玩家昵称
 *  @param gameLevel  角色等级
 *  @param appleProductId apple产品id 不参与签名校验
 *  @param sign  sign签名，由游戏服务器生成。生成规则请参考游戏服务器接口文档
 */
- (void)payWithAmount:(int)amount andCpOrderId:(NSString *)cpOrderId andProductName:(NSString *)productName andExtend:(id)extend andGameArea:(NSString*)gameArea andGameAreaId:(NSString*)gameAreaId andGameRoleId:(NSString*)roleId andUserRole:(NSString*)userRole andGameLevel:(NSString*)gameLevel andAppleProductId:(NSString*)appleProductId andsign:(NSString*)sign ;



/**
 *  提交角色信息
 *
 *
 *  @param areaName    角色所在服务区名称
 *  @param areaId   角色所在服务区ID
 *  @param roleId   角色ID
 *  @Param roleName  角色名或者玩家昵称
 *  @param roleLevel  角色等级
 *
 */

- (void)submitRoleData:(NSString*)roleId roleName:(NSString *)roleName areaId:(NSString *)areaId areaName:(NSString *)areaName roleLevel:(NSString *)roleLevel;

/**
 *  App间跳转回调，必须在appdelegate里的2个回调方法实现，参见demo
 *
 *  @param url appdelegate回调方法的url参数，原样传递进来
 *
 *  @return
 */
- (BOOL)handleOpenURL:(NSURL *)url;




#pragma mark -




@end
