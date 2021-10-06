//
//  HomeViewController.swift
//  Authentication
//
//  Created by Abraham Cepeda Oseguera on 29/09/21.
//

import UIKit
import Firebase

class HomeViewController: UIViewController {

    @IBOutlet weak var welcomeLbl: UILabel!
    @IBOutlet weak var nameTF: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        guard let userEmail = Auth.auth().currentUser?.email else {
            return
        }
        welcomeLbl.text = "Bienvenido \(userEmail)"
        // Do any additional setup after loading the view.
    }

    @IBAction func logout(_ sender: UIButton) {
        do {
            try? Auth.auth().signOut()
        }
        
    }
    
    @IBAction func savename(_ sender: UIButton) {
        guard let name = nameTF.text, !name.isEmpty else {
            return
        }
        let changeRequest = Auth.auth().currentUser?.createProfileChangeRequest()
        changeRequest?.displayName = name
        changeRequest?.commitChanges() { error in
            if error != nil {
                self.displayAlert(title: "Error", message: error?.localizedDescription ?? "No se pudo guardar el nombre")
            } else {
                guard let username = Auth.auth().currentUser?.displayName else {
                    return
                }
                self.welcomeLbl.text = username
            }
            
        }
        
    }
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
