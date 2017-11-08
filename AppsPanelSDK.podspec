Pod::Spec.new do |s|
  s.name         = "AppsPanelSDK"
  s.version      = "4.7.3"
  s.summary      = "AppsPanelSDK"
  s.homepage     = "http://www.appspanel.com/integration-sdk-mobile-backend/"
  s.license      = { :type => "Copyright", :file => "LICENSE" }
  s.author       = "Apps Panel"
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/appspanel/AppsPanelSDK", :tag => "#{s.version}"}

  # s.prefix_header_contents = '#import "APLogger.h"'

  s.vendored_frameworks = 'AppsPanelSDK.framework'
  s.resource = 'AppsPanelResources.bundle'

  s.frameworks      = 'AppsPanelSDK', 'ReplayKit', 'UIKit', 'AdSupport', 'SystemConfiguration', 'Security', 'Foundation', 'CoreTelephony', 'CoreMotion'
  s.ios.dependency 'JWT', '3.0.0-beta.2'
  s.ios.dependency 'Lockbox'
  s.ios.dependency 'APBanner'
end
