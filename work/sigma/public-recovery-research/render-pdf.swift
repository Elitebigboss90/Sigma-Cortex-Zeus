import Foundation
import AppKit
import PDFKit
let document=PDFDocument(url: URL(fileURLWithPath: CommandLine.arguments[1]))!
let page=document.page(at:0)!
let bounds=page.bounds(for:.mediaBox)
print("PDF bounds: \(bounds)")
let width:CGFloat=2800
let image=page.thumbnail(of:NSSize(width:width,height:width*bounds.height/bounds.width),for:.mediaBox)
let rep=NSBitmapImageRep(data:image.tiffRepresentation!)!
try rep.representation(using:.png,properties:[:])!.write(to:URL(fileURLWithPath:CommandLine.arguments[2]))
