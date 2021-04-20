using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Misile : MonoBehaviour
{
	//public float speed = 5.0f;
	private Rigidbody2D rb;

    // Start is called before the first frame update
    void Start()
    {
     rb = this.GetComponent<Rigidbody2D>();
     //rb.velocity = new Vector2(-speed, 0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter2D(Collider2D c)
    {
    	if(c.tag == "barrier"){
    		Destroy(this.gameObject);
    	} else if(c.tag == "Player"){
    		TextScript.scoreValue -= 10;
    		Destroy(this.gameObject);
    		if(TextScript.scoreValue == 0){
    			Time.timeScale = 0;
    		}
    	} else if(c.tag == "tankMissile"){
    		Destroy(this.gameObject);
    	}
    }
}
