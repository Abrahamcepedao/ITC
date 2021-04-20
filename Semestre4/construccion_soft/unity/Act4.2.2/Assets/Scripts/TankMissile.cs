using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TankMissile : MonoBehaviour
{

	private Rigidbody2D rb;


    // Start is called before the first frame update
    void Start()
    {
        rb = this.GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter2D(Collider2D c)
    {
    	if(c.tag == "barrier"){
    		Destroy(this.gameObject);
    	} else if(c.tag == "enemyTank"){
    		Destroy(this.gameObject);
    		EnemyTank.score -= 10;
    		if(EnemyTank.score == 0){
    			Destroy(c.gameObject);
    		}
    	} else if(c.tag == "enemyTank2"){
    		Destroy(this.gameObject);
    		EnemyTank2.score -= 10;
    		if(EnemyTank2.score == 0){
    			Destroy(c.gameObject);
    		}
    	} else if(c.tag == "enemyMissile"){
    		Destroy(this.gameObject);
    	}
    }
}
