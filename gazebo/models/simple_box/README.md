# modelを作成する
## modelの作成
- model.sdfとmodel.configの２つのファイルが必要
- それぞれが同じモデル名のディレクトリの中にある必要がある
## model.sdf
- `<model>`タグ内がモデルについての記述
    - 以下の3つの主の要素を記述する
    - `<interial>`タグは重さについての要素
        - 重量とイナーシャを記述する
            - 物理演算に使われる値
        - `<mass>`タグで重さ[kg]を記述する
        - `<inertia>`タグで慣性モーメントを記述する
            - 回転方向の慣性に相当する
            - 6パラメータで記述する
            - 簡単な図形であれば[これ](https://rivi-manufacturing.com/calculation-tool/1601/)で計算できる
    - `<collision>`タグでは衝突検出に使われる値を記述する
        - これが無いと無限に落ちてしまう
    - `<visual>`はGUIでの表示に使われる値
        - 基本は`<collision>`と同じ形にする
## 実行
以下のいずれかの方法によってパスを通す必要がある
### コマンドラインでパスを通して実行
gazeboで実行
```bash
cd models
export GAZEBO_MODEL_PATH=`pwd`:$GAZEBO_MODEL_PATH
cd worlds
gazebo box.world 
```
roslaunchで実行
```bash
cd models
export GAZEBO_MODEL_PATH=`pwd`:$GAZEBO_MODEL_PATH
cd worlds
roslaunch gazebo_ros empty_world.launch world_name:=`pwd`/box.world 
```
いずれもあまりスマートでない
## package.xmlに記述を加えてroslaunchで実行
```xml
<package>
    (中略)
    <exec_depend>gazebo_ros</exec_depend>
    <export>
        <gazebo_ros gazebo_media_path="${prefix}/worlds" />
        <gazebo_ros gazebo_medel_path="${prefix}/models" />
    </export>
</package>
```
`source ~/catkin_ws/devel/setup.bash`を実行後，以下を実行
```bash
roslaunch gazebo_ros empty_world.launch world_name:=~.world
```