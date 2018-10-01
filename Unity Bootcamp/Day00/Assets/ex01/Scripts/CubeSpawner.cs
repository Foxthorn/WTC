using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeSpawner : MonoBehaviour {

	public float timer;
	public float spawnTime;

	public List<GameObject> objects = new List<GameObject>();
	public List<GameObject> spawns = new List<GameObject>();
	public List<GameObject> endPoints = new List<GameObject>();
	public static bool[] active = new bool[3];
	private string[] tags = new string[3];
	// Use this for initialization
	void Start () {
		tags[0] = "A";
		tags[1] = "S";
		tags[2] = "D";
	}
	
	// Update is called once per frame
	void Update () {
		if (timer >= spawnTime)
		{
			int rng = Random.Range(0, 3);
			if (!active[rng])
			{
				timer = 0;
				active[rng] = true;
				Vector3 startPos = spawns[rng].transform.position;
				GameObject obj = (GameObject)Instantiate(objects[rng], startPos, Quaternion.identity);
				Debug.Log("Spawn: " + rng);			
				obj.tag = tags[rng];
			}
		}
		timer += Time.deltaTime;
	}
}
