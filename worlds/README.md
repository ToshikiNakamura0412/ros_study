# worldを作成する
## 実行
(ターミナルで`Ctrl-C`で落とそうとすると時間がかかるのでGUIの☓ボタンで落とす)
### gazebo単体で起動
```bash
gazebo ~.world
```
### ROSのlaunchから実行（フルパスで指定）
```bash
roslaunch gazebo_ros empty_world.launch world_name:=`pwd` /~.world
```
### ROSのlaunchから実行（環境変数でパスを通す）
```bash
export GAZEBO_RESOURSE_PATH=$GAZEBO_RESOURSE_PATH:`pwd`
roslaunch gazebo_ros empty_world.launch world_name:=~.world
```
### ROSのlaunchから実行（package.xmlでパスを通す）
今回であれば`gazebo/package.xml`に以下を追記
```xml
<package>
    (中略)
    <exec_depend>gazebo_ros</exec_depend>
    <export>
        <gazebo_ros gazebo_media_path="${prefix}/worlds" />
    </export>
</package>
```
`source ~/catkin_ws/devel/setup.bash`を実行後，以下を実行
```bash
roslaunch gazebo_ros empty_world.launch world_name:=~.world
```
## タグ 
- `<include>`はモデルを呼び出すタグ
    - 初期状態では`~/.gazebo/model`以下にあるモデルのみを呼び出せる
- `<uri>model://model-name<uri>`は呼び出すモデルを参照するタグ
    - `sun`と`groud_plane`はデフォルトのgazeboワールドにある要素
- `<name>`はモデルに名前をつけるタグ
- `<pose>`はモデルの出現位置を決めるタグ
    - 左からx, y, z, roll, pitch, yawを表す．回転の単位はdeg．
- `<static>`はモデルを固定するかどうかを決めるタグ
    - 省略するとfalse
        - 物理演算が適用されるのでぶつかれば動くし，重力の影響も受ける
    - trueにすると空間に固定される
        - ぶつかっても動かない
## トラブルシュート
### 対象のモデルが出てこない場合
以下の方法で操作して一度gazebo上に表示させることでローカルにキャッシュする必要がある<br>
(出てきている場合，~/.gazebo/models以下に保存されているはず)
1. gazeboを開く
1. 左側のウィンドウでInsertタブを開く
1. Connecting to model database...を押す
1. 数分待つ
1. http://models...の左の▲マークを押す
1. 対象のモデルを選択する
1. 3D viewの中を選択して出現させる
