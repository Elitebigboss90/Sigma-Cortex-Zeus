import Foundation
import ImageIO
import UniformTypeIdentifiers
for sourcePath in CommandLine.arguments.dropFirst() {
 let src=CGImageSourceCreateWithURL(URL(fileURLWithPath:sourcePath) as CFURL,nil)!
 let props=CGImageSourceCopyPropertiesAtIndex(src,0,nil)! as NSDictionary
 print(sourcePath,"width",props[kCGImagePropertyPixelWidth] ?? "?","height",props[kCGImagePropertyPixelHeight] ?? "?","orientation",props[kCGImagePropertyOrientation] ?? "?")
 let opts:[CFString:Any]=[kCGImageSourceCreateThumbnailFromImageAlways:true,kCGImageSourceCreateThumbnailWithTransform:true,kCGImageSourceThumbnailMaxPixelSize:6000]
 let image=CGImageSourceCreateThumbnailAtIndex(src,0,opts as CFDictionary)!
 let path="work/sigma/hardware-photos/"+URL(fileURLWithPath:sourcePath).deletingPathExtension().lastPathComponent+"-oriented.png"
 let dst=CGImageDestinationCreateWithURL(URL(fileURLWithPath:path) as CFURL,UTType.png.identifier as CFString,1,nil)!
 CGImageDestinationAddImage(dst,image,nil);assert(CGImageDestinationFinalize(dst))
 print(path,"render width",image.width,"height",image.height)
}
