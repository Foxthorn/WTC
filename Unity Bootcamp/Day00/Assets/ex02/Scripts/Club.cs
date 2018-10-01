using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Club : MonoBehaviour {

	private float power;
	public static bool isGameOver;
	public GameObject ball;
	private int score;
	private bool wasSpacePressed;
	// Use this for initialization
	void Start () {
		power = 0.0f;
		score = -15;
		isGameOver = false;
		wasSpacePressed = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (!isGameOver)
		{
			if (Input.GetKey("space") && Ball.speed == 0)
			{
				if (power <= 50)
					power += 1.0f;
				wasSpacePressed = true;
			}
			else if (Ball.speed == 0 && wasSpacePressed == true)
			{
				wasSpacePressed = false;
				Ball.direction = 1;
				Ball.speed = power;
				power = 0;
				transform.position = new Vector3(ball.transform.position.x - 1, 0.64f, 0);
				score += 5;
				Debug.Log("Score: " + Mathf.Clamp(score, -15, 0));
			}
		}
	}
}
