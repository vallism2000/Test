import bb.cascades 1.0

Container {
    
    id: ratingIndicator
    layout: AbsoluteLayout {
    }
    property int rating
   
    onRatingChanged: {
        console.log("Rating changed")
        star1.ratingChanged()
        star2.ratingChanged()
        star3.ratingChanged()
        star4.ratingChanged()
        star5.ratingChanged()

    }
    
    function ratingUpdate(){
     TestObject.updateRecipeRating(rating)   
    }
    
    ImageView {
        
        signal ratingChanged
        
        id: star1
        imageSource: "icon_martini_full.png" // would change to something else
        opacity: 0.25
        
        layoutProperties: AbsoluteLayoutProperties {
            positionY: 0
            positionX: 10
        }
        
        onTouch: {
            if (event.touchType == TouchType.Move || event.touchType == TouchType.Down){
                ratingIndicator.rating = 1
            } else if (event.touchType == TouchType.Up) {
                ratingIndicator.ratingUpdate()
            }
            
        }
        onRatingChanged: {
         if(rating >= 1){
             star1.imageSource = "icon_martini_full.png"
             star1.opacity = 1
             
         } else {
             star1.opacity = 0.25
             star1.imageSource = "icon_martini_empty.png"
        
         }      
       }
   }
   ImageView {
           
           signal ratingChanged
           
           id: star2
           imageSource: "icon_martini_full.png" // would change to something else
           opacity: 0.25
           
           layoutProperties: AbsoluteLayoutProperties {
               positionY: 0
               positionX: 72
           }
           
           onTouch: {
                if (event.touchType == TouchType.Move || event.touchType == TouchType.Down){
                    ratingIndicator.rating = 2
                } else if (event.touchType == TouchType.Up) {
                    ratingIndicator.ratingUpdate()
                }

           }
           onRatingChanged: {
            if(rating >= 2){
                star2.imageSource = "icon_martini_full.png"
                star2.opacity = 1
            
            } else {
                star2.opacity = 0.25
                star2.imageSource = "icon_martini_empty.png"  
            } 
            
          }
    }
      
    ImageView {
             
	     signal ratingChanged
	     
	     id: star3
	     imageSource: "icon_martini_full.png" // would change to something else
	     opacity: 0.25
	     
	     layoutProperties: AbsoluteLayoutProperties {
	         positionY: 0
	         positionX: 134
	     }
     
	     onTouch: {
	        if (event.touchType == TouchType.Move || event.touchType == TouchType.Down){
                ratingIndicator.rating = 3
            } else if (event.touchType == TouchType.Up) {
                ratingIndicator.ratingUpdate()
            }
	        
	         
	     }
	     onRatingChanged: {
	      if(rating >= 3){
	          star3.imageSource = "icon_martini_full.png"
	          star3.opacity = 1
	          
	      } else {
	          star3.opacity = 0.25
	          star3.imageSource = "icon_martini_empty.png"  
	      }     
	      
	    }
    }
    ImageView {
                     
       signal ratingChanged
         
       id: star4
       imageSource: "icon_martini_full.png" // would change to something else
       opacity: 0.25
         
       layoutProperties: AbsoluteLayoutProperties {
           positionY: 0
           positionX: 196
       }
         
         onTouch: {
             if (event.touchType == TouchType.Move || event.touchType == TouchType.Down){
                 ratingIndicator.rating = 4
             } else if (event.touchType == TouchType.Up) {
                 ratingIndicator.ratingUpdate()
             }
            
             
         }
         onRatingChanged: {
          if(rating >= 4){
              star4.imageSource = "icon_martini_full.png"
              star4.opacity = 1
              
          } else {
              star4.opacity = 0.25
              star4.imageSource = "icon_martini_empty.png"  
          }     
          
        }
    }
    ImageView {
                         
       signal ratingChanged
         
       id: star5
       imageSource: "icon_martini_full.png" // would change to something else
       opacity: 0.25
         
       layoutProperties: AbsoluteLayoutProperties {
           positionY: 0
           positionX: 258
       }
         
         onTouch: {
            if (event.touchType == TouchType.Move || event.touchType == TouchType.Down){
                ratingIndicator.rating = 5
            } else if (event.touchType == TouchType.Up) {
                ratingIndicator.ratingUpdate()
            }
           
             
         }
         onRatingChanged: {
          if(rating >= 5){
              star5.imageSource = "icon_martini_full.png"
              star5.opacity = 1
              
          } else {
              star5.opacity = 0.25
              star5.imageSource = "icon_martini_empty.png"  
          }     
          
        }
    }
}

