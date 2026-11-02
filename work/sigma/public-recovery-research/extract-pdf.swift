import Foundation
import PDFKit
let input = URL(fileURLWithPath: CommandLine.arguments[1])
guard let document = PDFDocument(url: input) else { fatalError("Invalid PDF") }
var output = ""
for i in 0..<document.pageCount {
    output += "\n--- PDF page \(i+1) ---\n" + (document.page(at:i)?.string ?? "") + "\n"
}
try output.write(toFile: CommandLine.arguments[2], atomically: true, encoding: .utf8)
print("Extracted \(document.pageCount) pages")
