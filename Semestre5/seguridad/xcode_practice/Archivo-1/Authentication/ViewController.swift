//
//  ViewController.swift
//  Authentication
//
//  Created by Miguel Cuellar on 02/09/21.
//

import UIKit
import FirebaseAuth

class ViewController: UIViewController {
    @IBOutlet weak var emailTxtField: UITextField!
    @IBOutlet weak var passwordTxtField: UITextField!
    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var signUpButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("Hay usuario? \(Auth.auth().currentUser?.uid)")
        setupViews()
    }
    
    func setupViews() {
        imageView.layer.cornerRadius = 12
        imageView.clipsToBounds = true
        
        signUpButton.layer.cornerRadius = 12
        signUpButton.clipsToBounds = true
        
    }

    @IBAction func signUp(_ sender: Any) {
        
        guard let email = emailTxtField.text, email != "" else {
            displayAlert(title: "Error", message: "El email no es válido")
            return
        }
        
        guard let password = passwordTxtField.text, password != "" else {
            displayAlert(title: "Error", message: "El password no es válido")
            return
        }
        
        Auth.auth().createUser(withEmail: email, password: password) { authResult, error in
            
            if error != nil {
                self.displayAlert(title: "Error", message: error?.localizedDescription ?? "")
                print(error)
            } else {
                print("Usuario registrado \(authResult?.user.uid ?? "")")
            }
        }
    }

}

