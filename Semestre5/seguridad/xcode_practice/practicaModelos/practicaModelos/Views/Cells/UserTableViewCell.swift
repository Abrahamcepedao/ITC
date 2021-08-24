//
//  UserTableViewCell.swift
//  practicaModelos
//
//  Created by Abraham Cepeda Oseguera on 23/08/21.
//

import UIKit

class UserTableViewCell: UITableViewCell {

    @IBOutlet weak var userImg: UIImageView!
    @IBOutlet weak var userLbl: UILabel!
    @IBOutlet weak var genderLbl: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
