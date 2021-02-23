using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovingGameObject : MonoBehaviour
{
    // Start is called before the first frame update
    Rigidbody2D rb;
    public Vector2 movement;
    public float speed = 1.0f;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        movement = new Vector2(0.0f, -2.0f);
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
}
