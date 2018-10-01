using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cube : MonoBehaviour {

	private float speed;
	// Use this for initialization
	void Start () {
		speed = Random.Range(2f, 3f);		
	}
	
	// Update is called once per frame
	void Update () {
		transform.Translate(Vector3.down * speed * Time.deltaTime);
		int objTag = 0;
		if (tag == "A") objTag = 0;
		if (tag == "S") objTag = 1;
		if (tag == "D") objTag = 2;

		float precision = transform.position.y;
		if (precision < -1) 
		{
			DeactivateGameObject(objTag, precision);
		}
		if (Input.GetKey("a") && CubeSpawner.active[objTag] && objTag == 0)
		{
			DeactivateGameObject(objTag, precision);
		}
		if (Input.GetKey("d") && CubeSpawner.active[objTag] && objTag == 1)
		{
			DeactivateGameObject(objTag, precision);
		}
		if (Input.GetKey("s") && CubeSpawner.active[objTag] && objTag == 2)
		{
			DeactivateGameObject(objTag, precision);
		}
	}

	void DeactivateGameObject(int i, float precision)
	{
		Destroy(transform.gameObject);
		CubeSpawner.active[i] = false;
		Debug.Log("Precision: " + precision);
	}
}
