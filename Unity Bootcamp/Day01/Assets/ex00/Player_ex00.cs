using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_ex00 : MonoBehaviour {

	public bool active = false;
	private float jumpForce = 20;
	private float gravity = 2;
	private bool jumping = false;
	private float jumpYPos;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (active)
		{
			if (Input.GetKey("right"))
			{
				transform.Translate(Vector3.right * Time.deltaTime);
			}
			if (Input.GetKey("left"))
			{
				transform.Translate(Vector3.left * Time.deltaTime);
			}
			if (Input.GetKeyDown("space") && jumping == false)
			{
				jumpYPos = transform.position.y;
				transform.Translate(Vector3.up * jumpForce * Time.deltaTime);
				jumping = true;
			}
			if (jumping == true)
			{
				transform.Translate(Vector3.down * gravity * Time.deltaTime);
				if (transform.position.y <= jumpYPos)
				{
					jumping = false;
					Vector3 temp = new Vector3(transform.position.x, jumpYPos, 0);
					transform.position = temp;
				}
			}
		}
	}

	public void ResetPosition(float x, float y)
	{
		Vector3 temp = new Vector3(x, y, 0);
		transform.position = temp;
	}
}
