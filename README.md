# Mini Bicycle

![img](./photos/size.jpg)

## Design

The model was created based on measurements of the Ghost Square Cross Essential (2021) bike, it is
scaled down to 1:3.5 so that it fits most 3D printers and most importantly smaller hardware like
bearings and screws can be used for joining parts and joints.

The scale was decided on based on the bottom bracket shell size, it has an inner diameter of 35mm
and the smallest bearing I had was 623 (3mm ID, 10mm OD).

All parts are under the [parts](./parts/) folder grouped based on their location on the bicycle.
Some parts have alternate designs, like the fork and dropouts have quick release and through axle
variants. In those cases the quick release one is preferred as it allows the wheels to be completely
assembled before mounting them.

![img](./photos/parts.jpg)

## Print

Some parts especially the frame tubes are very thin and long, in these cases orientation and cooling
are important.

Most parts will need some support, rectangular support is sufficient, for better looking parts the
hubs and saddle should be printed with tree supports.

### Post processing

Sanding is recommended, 100-300 grit is good finish for priming and paiting.

## Tolerancing

Parts use tolerances meant for 3D printed parts.

- 0.05 - 0.1mm is used for parts that are press-fit (e.g.: cassette to rear hub)
- 0.3 - 0.4mm is used for parts that move (e.g.: fork stanchions)

Additional clean up with tweezers or sandpaper might be necessary.

## Assembly

### Frame

Required hardware:

- Glue
- Rubber band (used as the chain)

Frame uses small slots that fit snugly, they can be glued together and optionally plastic welded for
a cleaner look.

The recommended order of gluing is:

1. Seatpost tube - Bottom bracket shell
2. Top tube - Seatpost tube
3. Down tube - Seatpost tube
4. Head tube - Top & Down tube
5. Chainstays - Rear dropouts
6. Seatstays (put chain on at this point) - Rear dropouts
7. Finally glue the top and bottom triangles together.

Optional parts:

- 2-4x M2 screws (4-5mm) for bottle cage mounting

### Fork

Required hardware:

- 1x M3 threaded insert (for securing headset)
- 2x Paper clips, staples or generally thin metal rods (as crosspins to retain the stanchions)
- 2x Small springs from a pen (as suspension springs)
- 2x MR128 bearing (as headset bearing)

Steps:

1. Place springs inside the arch
2. Push both stanchions in and retain them with the crosspins
3. Apply glue to the top of the stanchions
4. Finally push the crown on and hold it
5. Cut the crosspins flush and apply glue to their ends

### Crankset

Required hardware:

- 8x M3 nuts (used to secure the crank arms and space them)
- 4x M3 washers/spacers (used to space the hubs)
- 1x M3 threaded rod or a screw that's at least 45mm long (used as the spindle)
- 2x 623ZZ bearing (used as the bottom bracket bearing)
- 2x M2 screws that are at least 5mm long (used for pedals)

The amount of washers used can vary.

### Wheels

Generally required:

- Glue
- Wire or threads, width can be anything in the 0.5 - 1mm range
- [Wheel lacing tool](./tools/wheel-lacing/)
  - Requires 2x M5 threaded rods, M5 nuts and M3 threaded insert
- Tires
  - O-rings in the range of 175mm - 180mm can work
  - Polyurethane rubber can be used to mold them

#### Front wheel

Required hardware:

- 10x M3 nuts (used to space hub bearings and mounting in the fork)
- 2x M3 washers/spacers (used to space the hubs)
- 2x 623ZZ bearing (used as the hub bearing)
- 1x M3 threaded rod or a screw that's at least 40 mm long (used as the spindle)

#### Rear Wheel

Required hardware:

- 17x M3 nuts (used to space hub bearings and mounting in the rear dropouts)
- 2x M3 washers/spacers (used to space the hubs)
- 2x 623ZZ bearing (used as the hub bearing)
- 1x M3 threaded rod or a screw that's at least 56 mm long (used as the spindle)

### Wheel lacing

1. Center the lacing tool using calipers
2. Insert the 2 bearings into the hub with the spacers and 
3. Use a caliper to find the center of the wheel
4. Remove the spacers and mount the hub into the tool

Lacing is probably the easiest using a wire that goes from two holes in the rim through two holes
in the hub.

The dish doesn't have to be very accurate as it can be adjusted outside the tool once the spokes are
tightened.

### Seat Post

Required hardware:

- Glue
- 1x M3 screw at least 15mm in length (used to mount the saddle)

Steps:

- Glue the saddle to the saddle rail
- Mount the assembled saddle to the post using the screw

### Headset

Required hardware

- 1x M3 screw at least 30 mm long, countersunk (for mounting headset to steerer tube)
- 1x M2 screw at least 30 mm long (mounting handlebar with headset frontplate)
