using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour {

	public AudioClip move_sound;

	private Vector3 target;
	private Animator playerAnimator;
	private AudioSource sound;
	private float vol = 0.5f;
	public bool selected = false;
	private bool moving = false;
	// Use this for initialization
	void Start () {
		playerAnimator = GetComponent<Animator>();
		sound = GetComponent<AudioSource>();
	}
	
	// Update is called once per frame
	void Update () {
		if (selected || moving)
		{
			if (!moving)
				target = transform.position;
			if (Input.GetKeyDown(KeyCode.Mouse0) && selected && !Input.GetKey(KeyCode.LeftControl))
			{
				target = Camera.main.ScreenToWorldPoint(Input.mousePosition);
				moving = true;
				Animation(target);
			}
			transform.position = Vector2.MoveTowards(transform.position, target, Time.deltaTime);
			if (Vector2.Distance(target, transform.position) < 0.5f)
			{
				foreach(var parameter in playerAnimator.parameters) {            
					if (parameter.type == AnimatorControllerParameterType.Bool)
						playerAnimator.SetBool(parameter.name, false);         
				}
				playerAnimator.SetBool("Idle", true);
				moving = false;
			}
		}
	}

	void Animation(Vector2 direction)
	{
		float angle = Vector3.Angle(direction, transform.right);
		var cross = Vector3.Cross(direction, transform.right);
		if (cross.z < 0) 
			angle = 180f + (180 - angle);
		// Debug.Log(angle);
		foreach(var parameter in playerAnimator.parameters) {            
			if (parameter.type == AnimatorControllerParameterType.Bool)
       			playerAnimator.SetBool(parameter.name, false);         
		}
		if (angle > 50f && angle <= 120f)
			playerAnimator.SetBool("Down", true);
		if (angle > 120f && angle <= 150f)
			playerAnimator.SetBool("BottomLeft", true);
		if (angle > 150f && angle <= 200f)
			playerAnimator.SetBool("Left", true);
		if (angle > 200f && angle <= 230f)
			playerAnimator.SetBool("TopLeft", true);
		if (angle > 230f && angle <= 300f)
			playerAnimator.SetBool("Up", true);
		if (angle > 300f && angle <= 330f)
			playerAnimator.SetBool("TopRight", true);
		if (angle > 330f && angle <= 360f || angle > 0 && angle <= 20)
			playerAnimator.SetBool("Right", true);
		if (angle > 20 && angle <= 50)
			playerAnimator.SetBool("BottomRight", true);
		Sound();		
	}

	void Sound()
	{
		sound.PlayOneShot(move_sound, vol);
	}
}
