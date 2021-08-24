//
//  SecondViewController.swift
//  misDatos
//
//  Created by Abraham Cepeda Oseguera on 20/08/21.
//

import UIKit

class SecondViewController: UIViewController {

    @IBOutlet weak var matriculaLbl: UILabel!
    @IBOutlet weak var carreraLbl: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        matriculaLbl.text = "A00827666"
        carreraLbl.text = "ITC"
        // Do any additional setup after loading the view.
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
