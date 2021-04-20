using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PrimaryTank : MonoBehaviour
{
	Rigidbody2D rb;
	public Vector2 movement;
    public float speed = 7.0f;

    
    public GameObject missile;

    public Transform tankTip;


    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        movement = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));
        moveWithPosition();

        if(Input.GetMouseButtonDown(0))
        {
        	FireMissile();
        }

    }

    void moveWithPosition()
    {
    	rb.MovePosition((Vector2)transform.position  + (movement*speed*Time.deltaTime));
    }


    private void FireMissile()
    {	
    	GameObject newMissile = Instantiate(missile, tankTip.position, tankTip.rotation);
    	newMissile.GetComponent<Rigidbody2D>().velocity = tankTip.up * 5f;

    }

}
