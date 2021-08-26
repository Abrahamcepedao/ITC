//
//  ViewController.swift
//  DatosPersistentes
//
//  Created by Abraham Cepeda Oseguera on 26/08/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var redLbl: UILabel!
    @IBOutlet weak var greenLbl: UILabel!
    @IBOutlet weak var bueLbl: UILabel!
    
    @IBOutlet weak var redSlider: UISlider!
    @IBOutlet weak var greenSlider: UISlider!
    @IBOutlet weak var blueSlider: UISlider!
    
    let defaults = UserDefaults.standard
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        setUp()
    }

    func setUp(){
        redSlider.minimumValue = 0
        redSlider.maximumValue = 255
        
        greenSlider.minimumValue = 0
        greenSlider.maximumValue = 255
        
        blueSlider.minimumValue = 0
        blueSlider.maximumValue = 255
        
      
        let red: Float? = defaults.float(forKey: "red")
        let green: Float? = defaults.float(forKey: "green")
        let blue: Float? = defaults.float(forKey: "blue")
        if let redValue = red {
            redSlider.setValue(redValue, animated: true)
        }
        if let greenValue = green {
            greenSlider.setValue(greenValue, animated: true)
        }
        if let blueValue = blue {
            blueSlider.setValue(blueValue, animated: true)
        }

        redLbl.text = String(Int(redSlider.value))
        greenLbl.text = String(Int(greenSlider.value))
        bueLbl.text = String(Int(blueSlider.value))
        
        self.view.backgroundColor = UIColor(red: CGFloat(redSlider.value/255), green: CGFloat(greenSlider.value/255), blue: CGFloat(blueSlider.value/255), alpha: 1)
    }
    
    @IBAction func redSliderChange(_ sender: UISlider) {
        self.redLbl.text = String(Int(sender.value))
        self.view.backgroundColor = UIColor(red: CGFloat(sender.value/255), green: CGFloat(greenSlider.value/255), blue: CGFloat(blueSlider.value/255), alpha: 1)
        
        self.defaults.set(sender.value, forKey: "red")
    }
    
    @IBAction func greenSliderChange(_ sender: UISlider) {
        self.greenLbl.text = String(Int(sender.value))
        self.view.backgroundColor = UIColor(red: CGFloat(redSlider.value/255), green: CGFloat(sender.value/255), blue: CGFloat(blueSlider.value/255), alpha: 1)
        
        self.defaults.set(sender.value, forKey: "green")
    }
    
    @IBAction func blueSliderChange(_ sender: UISlider) {
        self.bueLbl.text = String(Int(sender.value))
        self.view.backgroundColor = UIColor(red: CGFloat(redSlider.value/255), green: CGFloat(greenSlider.value/255), blue: CGFloat(sender.value/255), alpha: 1)
        
        self.defaults.set(sender.value, forKey: "blue")
    }
}

