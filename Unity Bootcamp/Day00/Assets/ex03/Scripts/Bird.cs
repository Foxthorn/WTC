using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bird : MonoBehaviour {

	public static bool isBirdAlive;
	private float gravity = 3;
	private int jump = 50;
	public static int score;
	public GameObject pipe1;
	public GameObject pipe2;

	// Use this for initialization
	void Start () {
		score = 0;
		isBirdAlive = true;
	}

	void IsBirdAlive()
	{
		if (pipe1.transform.position.x < 1.4 && pipe1.transform.position.x > -1.4 && (transform.position.y < -1.7 || transform.position.y > 1.7))
			isBirdAlive = false;
		if (pipe2.transform.position.x < 1.4 && pipe2.transform.position.x > -1.4 && (transform.position.y < -1.7 || transform.position.y > 1.7))
			isBirdAlive = false;
		if (transform.position.y < -4)
			isBirdAlive = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (isBirdAlive)
		{
			transform.Translate(Vector3.down * gravity * Time.deltaTime);
			if (Input.GetKeyDown("space"))
				transform.Translate(Vector3.up * jump * Time.deltaTime);
			IsBirdAlive();
		}
		else
		{
			Debug.Log("Score: " + score);
			Debug.Log("Time: " + Mathf.RoundToInt(Time.time));
			Destroy(gameObject);
		}
	}
}
