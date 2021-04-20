using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyTank : MonoBehaviour
{
	Rigidbody2D rb;

	public Transform tankTip;

	public float time = 0.5f;

	public static int score = 100;

    // Start is called before the first frame update
    void Start()
    {
    	rb = GetComponent<Rigidbody2D>();
    	StartCoroutine(rotateTank());
        //InvokeRepeating("rotateTank", 2.0f, 0.5f);
    }

    // Update is called once per frame
    void Update()
    {
        //rotateTank();
    	/*var num = Random.Range(0f, 2f);
    	if(num == 0){
    		transform.Rotate(0,0,-5*time*);	
    	} else{
    		transform.Rotate(0,0,-5*time);
    	}*/
        
    }

    /*void rotateTank()
    {
    	Vector2 direction = new Vector2(
    		transform.position.x+10,
    		transform.position.y
    	);
    	transform.up = direction;
    }*/

    IEnumerator rotateTank(){
    	while(true){
    		yield return new WaitForSeconds(time);
    		Vector2 direction = new Vector2(
	    		tankTip.position.x - transform.position.x*Time.deltaTime,
	    		tankTip.position.y - transform.position.y*Time.deltaTime
	    	);

	    	transform.up = direction;
    	}
    }

}