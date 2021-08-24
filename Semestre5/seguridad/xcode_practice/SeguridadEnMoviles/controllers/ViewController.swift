//
//  ViewController.swift
//  SeguridadEnMoviles
//
//  Created by Abraham Cepeda Oseguera on 12/08/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var titleLbl: UILabel!
    @IBOutlet weak var printBtn: UIButton!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?){
        if segue.identifier == "SecondVCSegue"{
            guard let secondViewController = segue.destination as? SecondViewController else { return }
            secondViewController.nombre = "Andres"
        }
    }
    

}

