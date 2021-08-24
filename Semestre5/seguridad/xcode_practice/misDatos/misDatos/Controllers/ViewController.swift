//
//  ViewControllerr.swift
//  misDatos
//
//  Created by Abraham Cepeda Oseguera on 20/08/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var nameLbl: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()
        nameLbl.text = "Abraham Cepeda Oseguera"
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
