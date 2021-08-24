//
//  ViewController.swift
//  practicaModelos
//
//  Created by Abraham Cepeda Oseguera on 19/08/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var userImg: UIImageView!
    @IBOutlet weak var nameLbl: UILabel!
    @IBOutlet weak var genderLbl: UILabel!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
//        NetworkManager.getExternalData(fileLocation:)
        NetworkManager.getExternalData(fileLocation: "https://randomuser.me/api/", method:  .get, parameters: nil, stringParameters: nil) { (event: RandomUserRequest?, error) in
            if error != nil {
                print(error!)
            } else{
                if let randomUserRequest = event {
                    print(randomUserRequest.results.first?.name ?? "no name :(")
                    guard let user = randomUserRequest.results.first else { return }
                    self.nameLbl.text = "\(user.name.title). \(user.name.first) \(user.name.last)"
                    self.genderLbl.text = user.gender
                    let url = URL(string: user.picture.medium)!
                    self.userImg.downloaded(from: url)
                }
            }
        }
    }
    
    @IBAction func getUserTapped(_ sender: Any) {
        NetworkManager.getExternalData(fileLocation: "https://randomuser.me/api/", method:  .get, parameters: nil, stringParameters: nil) { (event: RandomUserRequest?, error) in
            if error != nil {
                print(error!)
            } else{
                if let randomUserRequest = event {
                    print(randomUserRequest.results.first?.name ?? "no name :(")
                    guard let user = randomUserRequest.results.first else { return }
                    self.nameLbl.text = "\(user.name.title). \(user.name.first) \(user.name.last)"
                    self.genderLbl.text = user.gender
                    let url = URL(string: user.picture.medium)!
                    self.userImg.downloaded(from: url)
                }
            }
        }
    }
    
    

}

