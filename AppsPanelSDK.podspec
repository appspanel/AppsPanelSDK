Pod::Spec.new do |s|
  s.name         = "AppsPanelSDK"
  s.version      = "4.9.0"
  s.summary      = "AppsPanelSDK"
  s.homepage     = "https://appspanel.readme.io/docs/ios-getting-started"
  s.license      = { :type => "Copyright", :file => "LICENSE" }
  s.author       = "Apps Panel"
  s.platform     = :ios, "10.0"
  s.source       = { :git => "https://github.com/appspanel/AppsPanelSDK.git", :tag => "#{s.version}"}

  # s.prefix_header_contents = '#import "APLogger.h"'

  s.vendored_frameworks = 'AppsPanelSDK.xcframework'
  s.resource = 'AppsPanelResources.bundle'

  s.frameworks      = 'ReplayKit', 'UIKit', 'AdSupport', 'SystemConfiguration', 'Security', 'Foundation', 'CoreTelephony', 'CoreMotion', 'WebKit'
  s.ios.dependency 'JWT', '3.0.0-beta.12'
  s.ios.dependency 'Lockbox'
  s.ios.dependency 'APBanner'
end
