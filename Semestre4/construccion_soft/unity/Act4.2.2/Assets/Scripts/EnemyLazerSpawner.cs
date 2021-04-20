using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyLazerSpawner : MonoBehaviour
{
    // Start is called before the first frame update
	public GameObject lazerPrefab;
	//public GameObject tank1;
	//public GameObject tank2;

	public Transform enemyTankTip1;
	public Transform enemyTankTip2;


    void Start()
    {
     	InvokeRepeating("LaunchLazer", 2.0f, 2.5f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void LaunchLazer()
    {
    	if(enemyTankTip1){
    		GameObject lazer1 = Instantiate(lazerPrefab, enemyTankTip1.position, enemyTankTip1.rotation);	
    		lazer1.GetComponent<Rigidbody2D>().velocity = enemyTankTip1.up * 5f;
    	}
    	
    	if(enemyTankTip2){
    		GameObject lazer2 = Instantiate(lazerPrefab, enemyTankTip2.position, enemyTankTip2.rotation);
    		lazer2.GetComponent<Rigidbody2D>().velocity = enemyTankTip2.up * 5f;	
    	}
    	

    	

    }
}
