using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spaceship : MonoBehaviour
{
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
        moveWithPosition();
    }

    void moveWithPosition()
    {
        rb.MovePosition((Vector2)transform.position + (movement * speed * Time.deltaTime));
    }

    private void OnTriggerEnter2D(Collider2D c)
    {
        if(c.tag == "Goal")
        {
            TextScript.goal = true;
            Time.timeScale = 0;
        }
        else if(TextScript.scoreValue > 10)
        {
            Destroy(c.gameObject);
            TextScript.scoreValue -= 10;
        }
        else
        {
            TextScript.scoreValue -= 10;
            Time.timeScale = 0;
        }
    }
}
