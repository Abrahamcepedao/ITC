using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;


public class TextScript : MonoBehaviour
{
    public static int scoreValue = 100;
    public static bool goal = false;
    public TextMeshProUGUI scoreText;

    // Start is called before the first frame update
    void Start()
    {
        scoreText = FindObjectOfType<TextMeshProUGUI>();
    }

    // Update is called once per frame
    void Update()
    {
        if(goal)
        {
            scoreText.SetText($"Total score: {scoreValue}");
        } else if(scoreValue >= 10)
        {
            scoreText.SetText($"Score {scoreValue}");
        }
        else
        {
            scoreText.SetText("Game Over!");
        }
        
        //scoreText.text = "Score: " + scoreValue;
    }
}