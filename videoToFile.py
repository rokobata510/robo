import numpy as np
import cv2


def video_to_array(video_path):
    # Open the video file
    cap = cv2.VideoCapture(video_path)
    
    # Check if the video capture object is opened successfully
    if not cap.isOpened():
        print("Error: Unable to open video file.")
        return
    
    # Get the total number of frames
    total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    
    # Set target dimensions
    target_width = 16
    target_height = 12
    
    # Initialize the 3D array
    video_array = np.zeros((target_width, target_height, total_frames), dtype=np.uint8)
    
    # Iterate through each frame
    for frame_num in range(total_frames):
        ret, frame = cap.read()
        if ret:
            # Convert frame to grayscale and downsample
            gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            downsampled_frame = cv2.resize(gray_frame, (target_width, target_height), interpolation=cv2.INTER_LINEAR)
            
            # Update the video array
            for x in range(target_width):
                for y in range(target_height):
                    # Threshold the grayscale pixel to binary (0 or 1)
                    video_array[x, y, frame_num] = 1 if downsampled_frame[y, x] > 127 else 0
        else:
            print(f"Error: Unable to read frame {frame_num} from the video.")
            break
    
    # Release the video capture object
    cap.release()
    
    return video_array

def save_array_to_file(video_array):
   # Save specified number of frames from the video array to a text file
    for frame_num in range(video_array.shape[2]):
        with open(f'frames/{frame_num + 1}.txt', 'w') as f:
            for y in range(video_array.shape[1]):
                line = ''.join(str(video_array[x, y, frame_num]) for x in range(video_array.shape[0]))
                f.write(line + '\n')


# Example usage
video_path = 'badApple.mp4'
array_result = video_to_array(video_path)

if array_result is not None:
    save_array_to_file(array_result)