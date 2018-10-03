using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_ex01 : MonoBehaviour {
	public bool active = false;
	public float jumpForce = 20;
	public float moveSpeed = 1;
	public Camera go;
	private CameraControl camera;
	private bool canJump = false;
	// Use this for initialization
	void Start () {
		camera = go.GetComponent<CameraControl>();
	}
	
	// Update is called once per frame
	void Update () {
		if (!camera.isGameWon)
		{
			if (active)
			{
				if (Input.GetKey("right"))
				{
					transform.Translate(Vector3.right * moveSpeed * Time.deltaTime);
				}
				if (Input.GetKey("left"))
				{
					transform.Translate(Vector3.left * moveSpeed * Time.deltaTime);
				}
				if (Input.GetKeyDown("space") && canJump)
				{
					transform.Translate(Vector3.up * jumpForce * Time.deltaTime);
					canJump = false;
				}
			}
		}
	}

	public void ResetPosition(float x, float y)
	{
		Vector3 temp = new Vector3(x, y, 0);
		transform.rotation = Quaternion.identity;
		transform.position = temp;
	}

	void OnCollisionEnter2D(Collision2D col)
    {
		transform.rotation = Quaternion.identity;
		canJump = true;
    }

    void OnTriggerExit2D(Collider2D other) {
		if (transform.name == "red" && other.gameObject.transform.name == "red_exit")
			camera.NotFinished(0);
		if (transform.name == "blue" && other.gameObject.transform.name == "blue_exit")
			camera.NotFinished(2);
		if (transform.name == "yellow" && other.gameObject.transform.name == "yellow_exit")
			camera.NotFinished(1);
    }

	void OnTriggerEnter2D(Collider2D col) 
	{
		if (transform.name == "red" && col.gameObject.transform.name == "red_exit")
			camera.setPlayerFinished(0);
		if (transform.name == "yellow" && col.gameObject.transform.name == "yellow_exit")
			camera.setPlayerFinished(1);
		if (transform.name == "blue" && col.gameObject.transform.name == "blue_exit")
			camera.setPlayerFinished(2);		
	}
}
