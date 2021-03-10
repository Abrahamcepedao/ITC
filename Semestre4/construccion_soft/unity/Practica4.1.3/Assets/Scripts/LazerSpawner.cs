using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LazerSpawner : MonoBehaviour
{
    public GameObject lazerPrefab;
    public GameObject player;
    //public float delayCreate = 2.0f;

    // Start is called before the first frame update
    void Start()
    {
        //StartCoroutine(EnemyFactor());
        InvokeRepeating("LaunchLazer", 2.0f, 0.5f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void LaunchLazer()
    {
        GameObject enemy = Instantiate(lazerPrefab) as GameObject;
        enemy.transform.position = new Vector2(Random.Range(-10.0f, 10.0f), (player.transform.position.y + 10.0f));
    }

    /*void SpawnLazer()
    {
        GameObject enemy = Instantiate(lazerPrefab) as GameObject;
        enemy.transform.position = new Vector2(Random.Range(-10.0f,10.0f), (player.transform.position.y + 2.0f));

    }

    IEnumerator EnemyFactor()
    {
        while (true)
        {
            yield return new WaitForSeconds(5);
            SpawnLazer();
        }
    }*/
}
