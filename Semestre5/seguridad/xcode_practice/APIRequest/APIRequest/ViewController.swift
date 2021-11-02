//
//  ViewController.swift
//  APIRequest
//
//  Created by Abraham Cepeda Oseguera on 12/10/21.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
//        let url = URL(string: "http://www.stackoverflow.com")!
//        var request = URLRequest(url: url)
//        request.httpMethod = "POST"
//
//        NSURLConnection.sendAsynchronousRequest(request, queue: OperationQueue.main) {(response, data, error) in
//            guard let data = data else { return }
//            print(String(data: data, encoding: .utf8)!)
//        }
        // Do any additional setup after loading the view.
//        let session = URLSession(configuration: URLSessionConfiguration.default, delegate: self, delegateQueue: nil)
//        urlSession?(session, didBecomeInvalidWithError: <#T##Error?#>)
        
        NetworkManager.getExternalData(fileLocation: "https://100.24.228.237:10032/exposicion/5b402e60-3975-4a91-8488-34ce634f5461", method:  .get, parameters: nil, stringParameters: nil) { (event: Exposicion?, error) in
            if error != nil {
                print(error!)
            } else{
                if let exposicion = event {
                    print(exposicion)
                }
            }
        }
        
//        let url = URL(string: "https://100.24.228.237:10032/exposicion/5b402e60-3975-4a91-8488-34ce634f5461")!
//        var request = URLRequest(url: url)
//        request.httpMethod = "GET"
//
//        NSURLConnection.sendAsynchronousRequest(request, queue: OperationQueue.main) {(response, data, error) in
//            guard let data = data else { return }
//            print(String(data: data, encoding: .utf8)!)
//        }
    }
    
//    func webRequest() {
//        let url = NSURL(string: "https://100.24.228.237:10032/exposicion/5b402e60-3975-4a91-8488-34ce634f5461")
//        let task = URLSession.sharedSession().dataTaskWithURL(url!) {
//            (data, response, error) in
//            if let dataReturned = data {
//               print(NSString(data: dataReturned, encoding: NSUTF8StringEncoding)!)
//            }
//        }
//
//        task.resume()
//        }
    
    
//    func test() {
//        NSLog("start")
//        let url = URL(string: "https://self-signed.badssl.com")!
//        let request = URLRequest(url: url, cachePolicy: .reloadIgnoringLocalCacheData, timeoutInterval: 60.0)
//        self.session.dataTask(with: request) { (data, response, error) in
//            if let error = error as NSError? {
//                NSLog("task transport error %@ / %d", error.domain, error.code)
//                return
//            }
//            let response = response as! HTTPURLResponse
//            let data = data!
//            NSLog("task finished with status %d, bytes %d", response.statusCode, data.count)
//        }.resume()
//    }
//
//    func urlSession(_ session: URLSession, didReceive challenge: URLAuthenticationChallenge, completionHandler: @escaping (URLSession.AuthChallengeDisposition, URLCredential?) -> Void) {
//        if challenge.protectionSpace.authenticationMethod == NSURLAuthenticationMethodServerTrust {
//            let trust = challenge.protectionSpace.serverTrust!
//            NSLog("is self-signed: %@", trust.isSelfSigned.flatMap { "\($0)" } ?? "unknown" )
//        }
//        completionHandler(.performDefaultHandling, nil)
//    }


}


//extension ViewController: URLSessionDelegate {
//    public func urlSession(_ session: URLSession, didReceive challenge: URLAuthenticationChallenge, completionHandler: @escaping (URLSession.AuthChallengeDisposition, URLCredential?) -> Void) {
//       //Trust the certificate even if not valid
//       let urlCredential = URLCredential(trust: challenge.protectionSpace.serverTrust!)
//
//       completionHandler(.useCredential, urlCredential)
//    }
//}

//extension SecTrust {
//
//    var isSelfSigned: Bool? {
//        guard SecTrustGetCertificateCount(self) == 1 else {
//            return false
//        }
//        guard let cert = SecTrustGetCertificateAtIndex(self, 0) else {
//            return nil
//        }
//        return cert.isSelfSigned
//    }
//}
//
//extension SecCertificate {
//
//    var isSelfSigned: Bool? {
//        guard
//            let subject = SecCertificateCopyNormalizedSubjectSequence(self),
//            let issuer = SecCertificateCopyNormalizedIssuerSequence(self)
//        else {
//            return nil
//        }
//        return subject == issuer
//    }
//}
