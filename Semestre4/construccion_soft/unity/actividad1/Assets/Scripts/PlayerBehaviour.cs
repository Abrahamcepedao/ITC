using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerBehaviour : MonoBehaviour{
    // Start is called before the first frame update
    Rigidbody2D rb;
    public Vector2 movement;
    public float speed = 10.0f;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        movement = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));
        //moveWithForce();
        //moveWithVelocity();
        moveWithPosition();
    }

    void moveWithForce()
    {
        rb.AddForce(movement * speed);
    }

    void moveWithVelocity()
    {
        rb.velocity = movement * speed;
    }

    void moveWithPosition()
    {
        rb.MovePosition((Vector2)transform.position + (movement * speed * Time.deltaTime));
    }

    private void OnTriggerEnter2D(Collider2D c)
    {
        Destroy(c.gameObject);
        TextScript.scoreValue -= 10;
        if(TextScript.scoreValue <= 0)
        {
            Destroy(gameObject);
        }
       //c.tag
    }
}
