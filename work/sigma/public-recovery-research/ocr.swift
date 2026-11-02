import Foundation
import Vision
import AppKit
let handler=VNImageRequestHandler(url:URL(fileURLWithPath:CommandLine.arguments[1]),options:[:])
let request=VNRecognizeTextRequest()
request.recognitionLevel = .accurate
request.recognitionLanguages = ["en-US"]
try handler.perform([request])
let observations=request.results ?? []
let output=observations.map { "\($0.boundingBox): \($0.topCandidates(1).first?.string ?? "")" }.joined(separator:"\n")
try output.write(toFile:CommandLine.arguments[2],atomically:true,encoding:.utf8)
print("OCR observations: \(observations.count)")
