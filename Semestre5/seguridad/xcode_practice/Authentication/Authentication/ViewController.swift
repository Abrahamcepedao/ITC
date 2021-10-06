//
//  ViewController.swift
//  Authentication
//
//  Created by Abraham Cepeda Oseguera on 02/09/21.
//

import UIKit
import FirebaseAuth

class ViewController: UIViewController {

    @IBOutlet weak var email: UITextField!
    @IBOutlet weak var password: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func logginPressed(_ sender: UIButton) {
        
        //handle firebase login
        guard let userEmail =  email.text else {
            print("no es válido el email")
            return
        }
        guard let userPassword = password.text else {
            print("No es valida la contraseña")
            return
        }
        
        Auth.auth().createUser(withEmail: userEmail, password: userPassword) { authResult, error in
            if error != nil {
                print(error)
            } else{
                print("usuario registrado \(authResult?.user.uid  ?? "no")")
            }
        }
    }
    
}

