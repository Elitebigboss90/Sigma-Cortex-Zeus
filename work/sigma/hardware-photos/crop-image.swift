import Foundation
import ImageIO
import UniformTypeIdentifiers
let src=CGImageSourceCreateWithURL(URL(fileURLWithPath:CommandLine.arguments[1]) as CFURL,nil)!
let image=CGImageSourceCreateImageAtIndex(src,0,nil)!
let r=CGRect(x:Double(CommandLine.arguments[3])!,y:Double(CommandLine.arguments[4])!,width:Double(CommandLine.arguments[5])!,height:Double(CommandLine.arguments[6])!)
let crop=image.cropping(to:r)!
let dst=CGImageDestinationCreateWithURL(URL(fileURLWithPath:CommandLine.arguments[2]) as CFURL,UTType.png.identifier as CFString,1,nil)!
CGImageDestinationAddImage(dst,crop,nil);assert(CGImageDestinationFinalize(dst))
print("Saved crop",r)
