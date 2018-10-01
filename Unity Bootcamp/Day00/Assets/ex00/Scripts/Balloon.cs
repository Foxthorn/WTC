using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Balloon : MonoBehaviour {

	private float breath = 100;
	private float size = 1f;
	private bool popped = false;
	private bool started = false;
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (!popped)
		{
			if (Input.GetKey("space"))
			{
				started = true;
				if (breath >= 10)
				{
					breath -= 15f;
					size += 0.2f;
					transform.localScale = new Vector3(size, size, 1f);
					if (size > 7)
					{
						size = 0;
						transform.localScale = new Vector3(size, size, 1f);
						Popped();
					}
				}
			}
			else if (started)
			{
				if (breath < 100)
					breath += 45f;
				if (size > 0)
					size -= 0.05f;
				else if (size > 7)
					Popped();
				transform.localScale = new Vector3(size, size, 1f);
			}
		}
	}

	void Popped()
	{
		popped = true;
		Debug.Log("Balloon life time: " + Mathf.RoundToInt(Time.time) + "s"); 
	}
}
