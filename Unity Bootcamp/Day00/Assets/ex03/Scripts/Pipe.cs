using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pipe : MonoBehaviour {

	private float speed = 1;
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (Bird.isBirdAlive)
		{
			transform.Translate(Vector3.left * speed * Time.deltaTime);
			if (transform.position.x < -8.9)
			{
				Vector3 temp = new Vector3(8.9f, 0, 0);
				transform.position = temp;
				Bird.score += 5;
			}
		}
		speed += 0.05f;
	}	
}
