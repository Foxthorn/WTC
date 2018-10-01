using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour {

	// Use this for initialization

	public static float speed;
	public static int direction;
	public static bool isBallInHole;
	void Start () {
		direction = 1;
		isBallInHole = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (speed > 0)
		{
			if (transform.position.x > 3.9 && transform.position.x < 4.1 && speed <= 3f)
			{
				Club.isGameOver = true;
				isBallInHole = true;
				speed = 0;
			}
			else
				speed -= 1.0f;
		}
		transform.Translate(Vector3.right * direction * speed * Time.deltaTime);
		if (transform.position.x > 6)
		{
			Vector3 temp = new Vector3(5.9f, 0, 0);
			transform.position = temp;
			direction *= -1;
		}
		if (transform.position.x < -8)
		{
			Vector3 temp = new Vector3(-7.9f, 0, 0);
			transform.position = temp;
			direction *= -1;
		}
	}

}
