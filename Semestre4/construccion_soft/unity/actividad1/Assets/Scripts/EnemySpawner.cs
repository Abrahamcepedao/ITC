using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    public GameObject enemyPrefab;
    public float delayCreate = 2.0f;

    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(EnemyFactor());
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void SpawnEnemy()
    {
        GameObject enemy = Instantiate(enemyPrefab) as GameObject;
        enemy.transform.position = new Vector2(2.0f, 10.0f);
        
    }

    IEnumerator EnemyFactor()
    {
        while (true)
        {
            yield return new WaitForSeconds(delayCreate);
            SpawnEnemy();
        }
    }
}
