Pod::Spec.new do |spec|
  spec.name         = "yourFramework"
  spec.version      = "0.0.1"
  spec.summary      = "A short description of yourFramework."

  spec.description  = <<-DESC
                   DESC

  spec.homepage     = "http://EXAMPLE/yourFramework"
  spec.license      = "MIT (example)"

  spec.author             = { "" => "" }

  spec.platform     = :ios, "8.0"

  spec.source       = { :git => "http://EXAMPLE/yourFramework.git", :tag => "#{spec.version}" }

  spec.source_files  = "Classes", "Classes/**/*.{h,m}"
  spec.exclude_files = "Classes/Exclude"

  spec.framework  = "ETGameSDKLib.framework"

end
